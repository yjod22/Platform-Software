# Platform Software

## Overview

It uses **separate Eclipse projects** for each application with shared code included directly:

```
Platform-Software/
├── Config/                   (Shared configuration)
├── MCAL/                     (Shared hardware abstraction layer)
├── Third-Party/              (Shared third-party libraries)
│
├── Applications/
│   ├── CanAnalyzer/          (Independent Eclipse project)
│   │   ├── .project
│   │   ├── .cproject
│   │   ├── APPL/
│   │   ├── EHAL/
│   │   ├── RTE/
│   │   ├── inc/
│   │   ├── src/
│   │   └── startup/
│   │
│   └── NewApp/               (Future application - same structure)
│       ├── .project
│       ├── .cproject
│       ├── APPL/
│       ├── EHAL/
│       ├── RTE/
│       ├── inc/
│       ├── src/
│       └── startup/
```

## Setup Instructions

### Step 1: Import Projects into System Workbench for STM32

1. Open System Workbench for STM32
2. **File** → **Import**
3. Select **General** → **Existing Projects into Workspace**
4. Browse to your `Platform-Software` folder
5. Check **Search for nested projects**
6. Select all discovered projects:
   - `Platform-Software`
   - `CanAnalyzer`
7. Click **Finish**

### Step 2: Build CanAnalyzer

1. Right-click **CanAnalyzer** project
2. **Build Project** (or press `Ctrl+B`)
3. Binary output: `Applications/CanAnalyzer/Debug/CanAnalyzer.bin` or `Applications/CanAnalyzer/Release/CanAnalyzer.bin`

## Adding a New Application (e.g., NewApp)

### Step 1: Create Folder Structure

Create `Applications/NewApp/` with this structure:

```
Applications/NewApp/
├── APPL/
│   ├── appl.c
│   └── appl.h
│
├── EHAL/
│   ├── adc/
│   │   ├── inc/
│   │   └── src/
│   ├── can/
│   │   ├── inc/
│   │   └── src/
│   ├── dio/
│   │   ├── inc/
│   │   └── src/
│   ├── exti/
│   │   ├── inc/
│   │   └── src/
│   ├── i2c/
│   │   ├── inc/
│   │   └── src/
│   ├── usart/
│   │   ├── inc/
│   │   └── src/
│   ├── ehal.c
│   └── ehal.h
│
├── RTE/
│   ├── inc/
│   ├── Rte.c
│   └── Rte.h
│
├── inc/
│   └── (app-specific headers)
│
├── src/
│   ├── main.c
│   ├── syscalls.c
│   └── system_stm32f4xx.c
│
└── startup/
    └── startup_stm32.s
```

### Step 2: Create .project File

Copy `Applications/CanAnalyzer/.project` to `Applications/NewApp/.project` and update the name:

```xml
<name>NewApp</name>
```

### Step 3: Create .cproject File

Copy `Applications/CanAnalyzer/.cproject` to `Applications/NewApp/.cproject` and replace all instances of:
- `CanAnalyzer` → `NewApp` (in workspace paths)
- Project ID references (unique IDs in cconfiguration)

Key sections to update:

```xml
<!-- Old -->
<builder buildPath="${workspace_loc:/CanAnalyzer}/Debug" ... />

<!-- New -->
<builder buildPath="${workspace_loc:/NewApp}/Debug" ... />
```

### Step 4: Import into System Workbench for STM32

1. **File** → **Import**
2. **General** → **Existing Projects into Workspace**
3. Select `Applications/NewApp`
4. Uncheck **Copy projects into workspace** (if it's already in your workspace)
5. Click **Finish**

### Step 5: Build NewApp

1. Right-click **NewApp** project
2. **Build Project**
3. Binary output: `Applications/NewApp/Debug/NewApp.bin` or `Applications/NewApp/Release/NewApp.bin`

## Key Points

### Linked Resources

Shared code directories (Config, MCAL, and Third-Party) are configured as **linked resources** in each application project. This setup uses the `Platform_Software` path variable defined in the workspace, allowing:

- Centralized shared code without duplication
- Easy updates to shared libraries across all applications
- Path independence - changes to folder locations only require updating the `Platform_Software` variable
- Cleaner project structure with symbolic links to shared resources

The linked resources are configured in each `.cproject` file to reference:
```
${Platform_Software}/Config
${Platform_Software}/MCAL
${Platform_Software}/Third-Party
```

### Include Paths Resolution

Each application project references shared code via these project-relative paths:

```
../../Config
../../MCAL/...
../../Third-Party/...
```

This allows:
- Independent build configurations per application
- Shared header files and libraries
- Easy dependency management

### Linker Script

Application linker scripts are located in their respective directories:

```
Applications/<AppName>/LinkerScript.ld
```
