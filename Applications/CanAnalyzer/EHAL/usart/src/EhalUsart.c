#include <usart/EhalUsart.h>
#include <usart/EhalUsart_CFG.h>
#include <usart/EhalUsart_IN.h>
#include <usart/EhalUsart_OUT.h>

/*
 * DEFINITION OF LOCAL MACROS/DEFINES
 * */

#define PACKET_MAX_SIZE 22U
#define STREAM_MAX_SIZE 50U
#define COBS_MAX_CODE 255U
#define DELIMITER 0U

/*
 * DEFINITION OF LOCAL TYPES
 * */

/*
 * DEFINITION OF LOCAL VARIABLES
 * */

/*
 * DEFINITION OF LOCAL CONSTANTS
 * */

/*
 * DECLARATION OF LOCAL FUNCTIONS
 * */

void composePacket(Rte_CanRx_tst* message, uint8_t* packet);

size_t encodePacket(uint8_t* packet, size_t packetSize, uint8_t* encodedData);

/*
 * DEFINITION OF GLOBAL VARIABLES
 * */

/*
 * IMPLEMENTATION OF GLOBAL FUNCTIONS
 * */

void EhalUsart_Init(void)
{
    EhalUsart_OUT_InitRcc();
    EhalUsart_OUT_InitGpio();
    EhalUsart_OUT_InitUsart();
}

void EhalUsart_SendCan(void)
{
    Rte_CanRx_tst canRx;
    uint8_t packet[PACKET_MAX_SIZE] = {0};
    size_t encodedSize = 0;
    uint8_t encodedData[STREAM_MAX_SIZE] = {0};

    while (EhalUsart_IN_Can(&canRx) == TRUE)
    {
        memset(packet, 0, sizeof(packet));
        encodedSize = 0;
        memset(encodedData, 0, sizeof(encodedData));

        composePacket(&canRx, packet);

        encodedSize = encodePacket(packet, sizeof(packet), encodedData);

        for (int i = 0; i < encodedSize; i++)
        {
            EhalUsart_OUT_SendData(encodedData[i]);
        }
    }
}

/*
 * IMPLEMENTATION OF LOCAL FUNCTIONS
 * */

void composePacket(Rte_CanRx_tst* message, uint8_t* packet)
{
    if ((message == NULL) | (packet == NULL))
    {
        return;
    }

    uint16_t offset = 0;

    memcpy(&packet[offset], &message->msgCounter, sizeof(message->msgCounter));
    offset += sizeof(message->msgCounter);

    memcpy(&packet[offset], &message->canRxMsg.StdId, sizeof(message->canRxMsg.StdId));
    offset += sizeof(message->canRxMsg.StdId);

    memcpy(&packet[offset], &message->canRxMsg.ExtId, sizeof(message->canRxMsg.ExtId));
    offset += sizeof(message->canRxMsg.ExtId);

    packet[offset++] = message->canRxMsg.IDE;
    packet[offset++] = message->canRxMsg.RTR;
    packet[offset++] = message->canRxMsg.DLC;

    memcpy(&packet[offset], message->canRxMsg.Data, sizeof(message->canRxMsg.Data));
    offset += sizeof(message->canRxMsg.Data);

    packet[offset++] = message->canRxMsg.FMI;
}

size_t encodePacket(uint8_t* packet, size_t packetSize, uint8_t* encodedData)
{
    /* Examples
     *
     * index:  0  1  2  3
     * packet: 00
     * result: 01 01 00
     *
     * index:  0  1  2  3
     * packet: 00 55 44
     * result: 01 03 55 44 00
     *
     * index:  0  1  2  3
     * packet: 55 44
     * result: 03 55 44 00
     *
     * index:  0  1  2  3  4  5  6
     * packet: 55 44 00 33 22
     * result: 03 55 44 03 33 22 00
     */

    if ((packet == NULL) || (encodedData == NULL) || (packetSize == 0))
    {
        return 0;
    }

    size_t writeIndex = 1;
    size_t codeIndex = 0;
    uint8_t code = 1;

    for (uint16_t i = 0; i < packetSize; ++i)
    {
        if (packet[i] == 0)
        {
            // Write the code byte and reset for the next block
            encodedData[codeIndex] = code;
            codeIndex = writeIndex++;
            code = 1;
        }
        else
        {
            // Copy non-zero byte to encoded data
            encodedData[writeIndex++] = packet[i];
            code++;

            // If the block is full, write the code byte
            if (code == COBS_MAX_CODE)
            {
                encodedData[codeIndex] = code;
                codeIndex = writeIndex++;
                code = 1;
            }
        }
    }

    // Write the final code byte
    encodedData[codeIndex] = code;

    // Append the COBS delimiter
    encodedData[writeIndex] = DELIMITER;

    return (writeIndex + 1); // Return the total size of the encoded data
}
