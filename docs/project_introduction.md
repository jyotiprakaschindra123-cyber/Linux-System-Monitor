# Project Introduction

## Project Title
Linux System Information & Monitoring Tool

## Problem Statement
Linux provides vital system information through various commands, pseudo-filesystems (like `/proc` and `/sys`), and system calls. For beginners or system administrators, checking information about the CPU, memory, disk, running processes, and network requires remembering and using multiple different commands or checking various locations. 

## Objective
The main objective of this project is to provide a single, unified command-line application that aggregates all this important system information and displays it in a clean, organized, and easy-to-read menu. Additionally, it aims to demonstrate the fundamentals of C++ programming and Linux system programming in a highly beginner-friendly way.

## Scope
This command-line tool will focus on providing basic monitoring capabilities, including:
- CPU details (Model, Cores)
- Memory usage (Total, Used, Available)
- Disk space availability
- Running process enumeration
- Basic network information
- System Uptime
- Report generation to a text file
- A simple device driver demonstration

## Expected Outcome
A modular, well-documented C++ application that successfully compiles and runs in a Linux environment. The code will be structured clearly without overly complex C++ features, allowing a beginner or intermediate student to easily understand, modify, and explain the project in an interview setting.

## Application / Use Case
This tool can be used as a lightweight monitoring utility on Linux servers or desktop environments to quickly assess system health without needing to install heavy dependencies or complex graphical monitoring tools. It also serves as an educational sandbox for understanding how user-space applications interface with the Linux kernel.
