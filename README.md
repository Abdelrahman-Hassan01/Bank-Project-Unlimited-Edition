<div align="center">

# 🏦 Bank Management System

### A feature-rich, console-based banking management system built with C++ and Object-Oriented Programming.

<p>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++">
  <img src="https://img.shields.io/badge/Standard-C%2B%2B20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++20">
  <img src="https://img.shields.io/badge/Platform-Windows-0078D4?style=for-the-badge&logo=windows&logoColor=white" alt="Windows">
  <img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white" alt="Visual Studio">
  <img src="https://img.shields.io/badge/Project-Educational-orange?style=for-the-badge" alt="Educational project">
</p>

<p>
  <b>Client Management</b> • <b>Banking Transactions</b> • <b>User Permissions</b> •
  <b>Transfer History</b> • <b>Currency Exchange</b>
</p>

</div>

---

## 📌 Overview

**Bank Management System** is a C++ console application that simulates the core operations of a small banking environment. It goes beyond a basic CRUD project by combining client account management, financial transactions, user authentication, permission-based access control, activity records, and currency exchange in one integrated application.

The project is built around Object-Oriented Programming principles. Its code is organized into separate **Core**, **Models**, and **Screens** layers to keep the main application flow, business/data logic, and console interface responsibilities more organized.

The application uses text files for persistent storage, allowing client records, user accounts, transfer history, login records, and currency data to remain available between runs.

> ⚠️ **Educational project — not production banking software.** It is intended for learning and demonstrating C++ programming and OOP concepts. It does not provide the security, reliability, regulatory compliance, or transactional guarantees required by a real banking system.

---

## ✨ Features

<details open>
<summary><b>👥 Client & Account Management</b></summary>

- Add new bank clients and create account records.
- Display a list of registered clients.
- Find clients using their account number.
- Update client information.
- Delete client records.
- Check whether an account number already exists.
- Store client information and account balances in a local data file.
- Apply input checks before accepting important data.

</details>

<details>
<summary><b>💸 Banking Transactions</b></summary>

- **Deposit:** Add money to a client's account.
- **Withdraw:** Withdraw money while checking the available balance.
- **Transfer:** Move money between two different client accounts.
- **Total Balances:** Display the combined balances of all clients.
- Validate transaction amounts and available balances.
- Prevent transfers to the same account.
- Save transaction-related data for later review.

</details>

<details>
<summary><b>🧾 Transfer History & Audit Records</b></summary>

The transfer log records information such as:

- Transfer date and time.
- Source account number.
- Destination account number.
- Transfer amount.
- Source balance after the transfer.
- Destination balance after the transfer.
- The username associated with the operation.

A separate login-register screen displays recorded login activity.

</details>

<details>
<summary><b>🔐 User Management & Access Control</b></summary>

- Authenticate users through a login screen.
- Add, find, update, list, and delete system users.
- Assign permissions when creating or updating a user.
- Check permissions before allowing access to protected sections.
- Support a full-access permission.
- Record successful login activity.
- Limit failed login attempts.

The permission system uses individual permission flags for different application operations.

</details>

<details>
<summary><b>💱 Currency Exchange</b></summary>

- Display the available currencies.
- Find a currency by country or currency code.
- Update a stored currency exchange rate.
- Convert an amount between currencies using USD as the base currency.
- Store currency information locally.

</details>

---

## 🧱 Project Architecture

The source code is separated into three main areas:

| Layer | Responsibility |
|---|---|
| `Core/` | Application flow, login, main menu, shared screen behavior, and global state. |
| `Models/` | Main data models and business operations, including clients, users, people, and currencies. |
| `Screens/` | Console screens and user interaction for clients, transactions, users, and currencies. |

### Main model classes

- **`clsPerson`** — shared personal information used by other models.
- **`clsBankClient`** — client account data and operations such as saving, deposits, withdrawals, transfers, and transfer-log handling.
- **`clsUser`** — user information, authentication-related operations, permissions, and login records.
- **`clsCurrency`** — currency information, exchange rates, lookup, and conversion.

### Data files

The application uses local text files for persistence:

| File | Purpose |
|---|---|
| `Clients.txt` | Client and account records. |
| `Users.txt` | System user records. |
| `TransferLog.txt` | Transfer history. |
| `LoginRegister.txt` | Login activity records. |
| `Currencies.txt` | Currency names, codes, countries, and rates. |

Records are serialized into text lines and parsed back into model objects when the application loads its data.

---

## 🛠️ Technologies & Concepts

- **C++20**
- Object-Oriented Programming (OOP)
- Classes, objects, constructors, and inheritance
- Encapsulation through private data and public interfaces
- Static member functions
- Enums and permission flags
- STL containers, including `vector` and `string`
- File handling with `fstream` and `ifstream`
- Input validation
- Data serialization and parsing
- Separation of application logic and console presentation
- Basic reversible text transformation for selected stored values

---

## ▶️ Getting Started

### Requirements

- Windows
- Microsoft Visual Studio with the C++ desktop development workload
- A C++20-compatible MSVC toolset
- The project's custom **MyLib** dependency

### Build and run

1. Clone or download this repository.
2. Open the Visual Studio solution/project.
3. Make sure the custom `MyLib` headers and library are available on your machine.
4. Review the file paths used by the data-loading and data-saving functions. The current source uses machine-specific absolute Windows paths; update them to paths that exist on your computer, preferably relative paths.
5. Select the desired configuration and platform in Visual Studio.
6. Build the project and run the application.

> **Dependency note:** The Visual Studio project currently references `MyLib.lib` and a local `C:\MyLib` directory. The dependency must be provided and configured separately; it is not included as a portable dependency in this source archive.

---

## 🔒 Security & Data Notice

This repository is a learning project, not a secure authentication or banking platform.

- The current code uses a custom reversible transformation for selected PIN/password values. This should **not** be considered secure password hashing or modern encryption.
- Do not use real customer information, real account credentials, or sensitive personal data.
- Do not commit your personal data files or populated login/transfer logs.
- Before publishing, replace sample records with empty or clearly fictional demo data.
- For a real application, use a standard password-hashing algorithm with salts, secure secret handling, safer storage, and proper transaction guarantees.

---

## 🗺️ Possible Future Improvements

- Replace machine-specific file paths with configurable, portable paths.
- Separate storage logic behind a repository/data-access layer.
- Replace text-file persistence with a database.
- Add automated unit and integration tests.
- Improve error handling and recovery from failed file operations.
- Use secure password hashing instead of reversible transformations.
- Make transfers atomic so a partial failure cannot leave account balances inconsistent.
- Add a graphical user interface.

---

## 🎯 Project Purpose

This project was created as a practical way to apply C++ and OOP concepts in a larger, multi-part application. It brings several related subsystems together and provides hands-on experience with modeling data, organizing code, validating input, handling files, managing permissions, and implementing operations that affect multiple records.

---

<div align="center">

**Built with C++ — focused on learning, problem-solving, and improving software design.**

</div>
