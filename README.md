<h1 align = "center">SAP-1</h1>
<p align = "center">Architecture of a microcomputer according to Albert Malvino</p>

## Architecture
<p align = "center"><img src= "https://i.imgur.com/o70alRf.png" width = "500px"/></p>

### PROM
The 16x8 PROM. It stores the 16 words of 8 bits each. These words, located at addresses 0 to F, are symbolized by R0, R1, R2..., Rf. When ER is high, the address of the word is read on the bus W.
### Instruction Register
The content of the instruction record is divided into two smaller words. words. The four most significant bits (most significant bits) are a two-state output that goes directly to the control unit. The four least significant bits correspond to the address of the register to be worked on in the ROM. is located in the ROM memory.
### Control Unit
CON is like the conductor of a symphony. It synchronizes and orchestrates and orchestrates all the different parts of the SAP-1 computer. by generating different routines, CON makes the other circuits fetch an instruction, load the accumulator with an instruction, load the accumulator with a number, add two numbers, and so on. two numbers, etc.
### Accumulator A
The accumulator (A) is a group of flip-flops that stores the response while the computer is running. while the computer is running. The accumulator has two outputs. The two-state output goes directly to the arithmetic logic unit. - arithmetic unit. The three-state output is connected to the W bus, the 8-bit word is carried from the accumulator to the ALU; the same word appears on the W-bus when the W-bus word appears on the W bus when EA is high.
### B Register
This register is used to perform all operations with the accumulator. A high 𝑳𝑩 and a positive clock edge load the bus word W into the B register. The two-state output of register B goes to the ALU, delivering the number to be added to or subtracted from the contents of the accumulator.
### ALU
It is in charge of performing the artimetic operations on what comes from the A Accumulator and the B Register.
### Output Register
Obtains what is on the W bus, and allows it to be taken outside.
### Binary Display
The Binary Display is a device of 8 light-emitting diodes (LEDs). (LEDs ). Since each LED is connected to a flip-flop of the output register, the binary display shows the contents of the output register. the binary display shows the contents of the output register. In addition, after having transferred a response from the accumulator to the output register, we can see the response of the output register. output register, we can see the response in binary form.

## Basic Instuctions
### LDA
If LDA is activated, the value associated with the RX is loaded into the accumulator.
### ADD
If ADD is active, the value associated with the RX function is loaded into register B and the sum is performed in the ALU, and the intermediate result is stored in the A accumulator.
### SUB
If ADD is active, the value associated with the RX function is loaded into register B and the sub is performed in the ALU, and the intermediate result is stored in the A accumulator.
### OUT
If OUT is active, the intermediate result in the accumulator A will be loaded to the bus to be loaded by the output register and then exposed to the outside world with the binary display.
### HLT
If HLT is active, terminates execution.

## About the project
There are several files in the repository, including:
- **SAP-1.pdsprj**: Proteus file where the simulation of the microcomputer is performed.
- **ICPROG_PROGRAMAS**: Documentation on how some operations are organized in the PROM, with their respective representation in binary, assembles and hexadecimal.
- **CODIGO_PC**: Code that controls the advance of the counter to change instruction.
- **CODIGO_DISPLAY_DECIMAL**: Code that converts from hexadecimal to decimal on the display.
- **CODIGO_ARDUINO**:Code that controls each of the corresponding actions coming from and going out of the CON. Heart of program execution.
- **ARCHIVOS_COMPILACIÓN**:Pre-compiler files for quicker project testing.
  
## Author
Kristian Restrepo Osorio - [Github](https://github.com/kristianrpo)
