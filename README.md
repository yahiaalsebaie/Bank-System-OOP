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

### 📜 License : **MIT**
