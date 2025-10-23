# Embedded Firmware Portfolio – TM4C123GXL 💡

### Overview
This repository contains a collection of embedded C projects developed for the **Texas Instruments TM4C123GXL Tiva LaunchPad**.  
Each project explores a specific concept in **firmware design, bitwise logic, and microcontroller GPIO control**.  
The goal of this portfolio is to demonstrate growth from basic hardware control to structured, documented firmware development.

---

### 🔧 Projects Overview

| Project | Description | Key Concepts |
|----------|--------------|---------------|
| [Single LED Control](./SingleLED) | Turns one LED on/off through GPIO manipulation | GPIO setup, digital output |
| [Combine LEDs](./CombineLEDs) | Lights multiple LEDs at once with bit masks | Bit masking, GPIO multiplexing |
| [Bit Shifts](./BitShifts) | Demonstrates shifting operations for LED control | Bitwise shift operations (`<<`, `>>`) |
| [Binary LED Counter](./BinaryLEDcounter) | Displays binary values (0–7) using RGB LEDs | Bitwise logic, loops, delays |
| [Binary Christmas Tree](./BinaryChristmasTree) | Binary LED counter with festive animation and flashing sequence | Bitwise logic, control flow, delay timing |

---

### 🧠 Skills Demonstrated
- Embedded **C programming** for ARM Cortex-M4  
- **GPIO configuration** and LED interfacing  
- **Bitwise operations** (`&`, `|`, `~`, `^`, `<<`, `>>`)  
- **Firmware structure** and modular organization  
- **Delay functions** and timing management  
- **Version control** using Git and GitHub  

---

### ⚙️ Hardware Setup
All projects use the **onboard LEDs** of the TM4C123GXL LaunchPad:

| LED Color | Pin | Binary Bit | Function |
|------------|-----|-------------|----------|
| Red | PF1 | Bit 0 | LSB (1) |
| Blue | PF2 | Bit 1 | Middle bit (2) |
| Green | PF3 | Bit 2 | MSB (4) |

Power and programming are done via USB using **Keil µVision** or **Code Composer Studio**.

---

### 📁 Repository Structure
firmware-portfolio/
├── BinaryChristmasTree/
│ ├── src/
│ ├── docs/
│ └── README.md
├── BinaryLEDcounter/
│ ├── src/
│ ├── docs/
│ └── README.md
├── BitShifts/
│ ├── src/
│ ├── docs/
│ └── README.md
├── CombineLEDs/
│ ├── src/
│ ├── docs/
│ └── README.md
├── SingleLED/
│ ├── src/
│ ├── docs/
│ └── README.md
└── README.md ← (this file)


Each project contains:
- `/src` → Source code and Keil/CCS project files  
- `/docs` → Diagrams, LED photos, and design notes  
- `README.md` → Project-specific explanation

---

### 📈 Progression of Learning
1. **Single LED** → Learn basic GPIO control  
2. **Combine LEDs** → Understand simultaneous LED activation  
3. **Bit Shifts** → Practice efficient register manipulation  
4. **Binary LED Counter** → Apply loops and bitwise logic  
5. **Binary Christmas Tree** → Combine all prior skills into a fun, animated LED sequence  

---

### 🚀 Tools Used
- **Keil µVision 5** for building and flashing firmware  
- **Git & GitHub** for version control and collaboration  
- **TivaWare SDK** for peripheral driver reference  
- **TM4C123GXL LaunchPad** development board  

---

### 📸 Example Output
Example LED output for binary counting:
| Decimal | Binary | LED Pattern |
| ------- | ------ | ----------- |
| 0       | 000    | [   ]       |
| 1       | 001    | [R  ]       |
| 2       | 010    | [ B ]       |
| 3       | 011    | [R B]       |
| 4       | 100    | [  G]       |
| 5       | 101    | [R G]       |
| 6       | 110    | [ B G]      |
| 7       | 111    | [R B G]     |


---

### 🧑‍💻 Author
**Edwin Sedano**  
Embedded Firmware Developer in Training  
📫 [GitHub Portfolio](https://github.com/e-sedano/firmware-projects.git)

---

