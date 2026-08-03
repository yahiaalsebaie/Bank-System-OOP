# 🏦 Bank Management System (OOP Architecture)

A highly structured, enterprise-grade Console Bank Management System engineered in **C++11**. This system represents a complete structural evolution from a traditional procedural paradigm into a strictly decoupled, robust **Object-Oriented Architecture (OOP)**. 

The application isolates core system layers, implements custom data properties for clean encapsulation, and handles security management using safe, low-level bitwise validation operations.

---

### 🔄 Architectural Evolution

This system is built entirely on modern object-oriented software engineering principles:
* **Strict Domain Encapsulation:** Core records (Clients and Users) are guarded through private properties, utilizing optimized memory models to avoid loose access states.
* **Isomorphic Inheritance:** UI components and fundamental entity contracts inherit cleanly from abstract foundations (e.g., identity properties flowing directly from a base `clsPerson` blueprint).
* **Decoupled Architecture:** User Interface rendering logic is entirely physically separated from core text-file data persistence and calculation layers.
* **Compiler-Driven Routing:** Subsystem headers are indexed cleanly using Additional Include Directories via compilation configurations, avoiding explicit relative path pollution (`#include "../../file.h"`).

> 🔗 **Looking for the Procedural Version?** You can view the original procedural implementation repository here: [https://github.com/yahiaalsebaie/Bank-Management-System-Cpp](https://github.com/yahiaalsebaie/Bank-Management-System-Cpp)

---

### 🛠️ System Modules & Component Screens

The system is physically mapped into dedicated operational layers, providing an intuitive, command-driven administrative terminal dashboard:

#### 1. Security & Authentication Gateway
* **Login Screen:** Restricts dashboard initialization to authorized operators through safe runtime input scanning.

#### 2. Client Operations Sub-domain
* **Show Client List:** Renders an aligned tabular view of all registered bank accounts and total dynamic records.
* **Add New Client:** Captures, sanitizes, and appends unique account numbers and client profiles.
* **Delete Client:** Stages and executes safe account record removal protocols.
* **Update Client Info:** Provides contextual editing capabilities for verified client fields.
* **Find Client:** Runs instant, optimized record seek algorithms across active storage buffers.

#### 3. Transaction Sub-domain
* **Central Transactions Menu:** Access point routing to processing mechanisms.
* **Deposit Screen:** Safely increments client balances with immediate transactional persistence.
* **Withdraw Screen:** Executes structural balance checking before allowing secure currency deductions.
* **Total Balances Monitor:** Dynamically maps aggregate cash liquidity across all active system accounts.

#### 4. Administrative Sub-domain (User Management)
* **Manage Users Menu:** Secured control room allowing administrators to create, query, modify, or erase system user profiles and alter access rights.

---

### 🚀 Immediate Evaluation & Testing Guide

For quick auditing and interactive verification of the system's operational features and access control limits, you can log in immediately using the pre-configured test profiles below:

#### 🔐 Full Administrative Access (All Permissions)
* **Username:** `User2`
* **Password:** `1234`
* **Capability:** Grants unrestricted access to all modules, screens, financial operations, and user access panels.

#### 🚷 Restricted Guest Access (Zero Permissions)
* **Username:** `User1`
* **Password:** `1234`
* **Capability:** Demonstrates the system's strict security layer. Accessing any module will be safely blocked, showing an access denied notice.

> 🛠️ **Testing Recommendation:** Log in as `User2`, navigate to the **Manage Users** module, add a new profile or modify `User1`'s permissions, and switch sessions to watch the bitwise access engine adjust controls dynamically in runtime.

---

### 🛑 Sandbox Testing Disclaimer
* **Data Context:** All profiles, financial entries, balances, names, and credentials present in the flat-file database (`Users.txt` / `Clients.txt`) are strictly simulated and **fictional**. They exist entirely for learning, sandbox execution, debugging, and testing purposes.

---

### 💻 Prerequisite Environment & Setup
* **IDE/Compiler:** Microsoft Visual Studio 2022 (with Desktop Development with C++ package)
* **Language Standard:** C++11 or higher configured in the project properties

#### Execution Instructions:
1. Clone this repository locally.
2. Open `Bank-System-OOP.sln` inside Visual Studio.
3. Build the project using `Ctrl + Shift + B` under `Debug / x64`.
4. Press `F5` to execute the terminal banking platform.

---
## 💻 Related Projects

If you'd like to explore more of my C++ journey and see how I build data structures, algorithms, and complete applications from scratch, check out these repositories.

---

### 📚 C++ Data Data Structures & Algorithms From Scratch

A collection of advanced Data Structures and Algorithms implemented completely from scratch in C++.

This repository contains:

- Custom implementations of Linked List, Stack, Queue, Dynamic Array, String, and more.
- Every data structure includes a dedicated **test file (.cpp)** with practical examples.
- Multiple implementations of the same project to compare different approaches (Custom Data Structures vs STL).
- Solutions and projects from **Programming Advices – Algorithms & Problem Solving Level 5** course.

Most of these classes are extensions of the libraries available in **MyCppToolboxLibraries**.

https://github.com/yahiaalsebaie/CppDataStructuresFromScratch

---

### 🔧 MyCppToolboxLibraries

My personal C++ library built completely from scratch.

It contains reusable utility classes that I developed throughout my programming journey, including:

- Date & Time
- String
- Input Validation
- Utility Functions
- Period
- And many more...

Many of the projects below are built on top of these libraries.

https://github.com/yahiaalsebaie/MyCppToolboxLibraries

---

### 🏦 Bank System (OOP)

Object-Oriented implementation of a complete banking system.

Includes the Currency Exchange project.

https://github.com/yahiaalsebaie/Bank-System-OOP

---

### 🏦 Bank Management System (Procedural Programming)

The same banking system implemented using Procedural Programming.

https://github.com/yahiaalsebaie/Bank-Management-System-Cpp

---

### 🏧 ATM System

Complete ATM simulation.

https://github.com/yahiaalsebaie/ATM-System-Course08

---

### 📅 Dual Calendar System

Gregorian & Hijri Calendar Library.

Features:

- Date calculations
- Date arithmetic
- Historical dates
- Astronomical calculations
- Date differences

https://github.com/yahiaalsebaie/Dual-Calendar-System-MiladiAndHijiri

---

### 🎮 Math Game

Console Math Game.

https://github.com/yahiaalsebaie/cpp-Math-Game

---

### ✂️ Stone Paper Scissors Game

Console implementation of the classic game.

https://github.com/yahiaalsebaie/stone-paper-scissors-cpp-game

---

# ⭐ If you find this repository useful...

Please consider giving it a ⭐.

It helps others discover the project and motivates me to continue improving it.

---


### 📜 License : **MIT**
