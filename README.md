<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:050816,45:14213D,100:6C2BD9&height=210&section=header&text=BANK%20MANAGEMENT%20SYSTEM&fontSize=35&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=UNLIMITED%20EDITION%20%E2%80%A2%20C%2B%2B20&descSize=18&descAlignY=58" width="100%" alt="Bank Management System - Unlimited Edition">

<a href="https://git.io/typing-svg">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=19&pause=1100&color=38BDF8&center=true&vCenter=true&width=700&lines=Beyond+CRUD...;Object-Oriented+Banking+Application;Clients+%7C+Transactions+%7C+Permissions;Built+with+C%2B%2B20" alt="Animated typing introduction">
</a>

<br>

<img src="https://img.shields.io/badge/C%2B%2B-20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++20">
<img src="https://img.shields.io/badge/Paradigm-OOP-7C3AED?style=for-the-badge" alt="OOP">
<img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows">
<img src="https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white" alt="Visual Studio">
<img src="https://img.shields.io/badge/Project-Educational-F59E0B?style=for-the-badge" alt="Educational project">

<br><br>

**A feature-rich, console-based banking management system developed in C++ using Object-Oriented Programming.**

[Overview](#-overview) • [Features](#-features) • [Architecture](#-architecture) • [Setup](#-getting-started) • [Security](#-security-notice)

</div>

---

## <img src="https://img.shields.io/badge/01-OVERVIEW-2563EB?style=flat-square" alt="01 Overview">

**Bank Management System — Unlimited Edition** is a C++ console application that simulates several operations found in a small banking environment.

This project goes beyond a basic CRUD application. It brings together client and account management, financial transactions, user authentication, permission-based access control, activity logs, and currency exchange in one integrated system.

The code is organized into separate **Core**, **Models**, and **Screens** areas. This separation helps keep application flow, data/business operations, and console interaction responsibilities distinct.

The application uses local text files to persist its records between runs.

> [!IMPORTANT]
> **Educational project — not production banking software.** This project is intended for learning and demonstrating C++ and OOP concepts. It does not provide the security, reliability, regulatory compliance, or transactional guarantees required by a real banking system.

---

## <img src="https://img.shields.io/badge/02-FEATURES-7C3AED?style=flat-square" alt="02 Features">

<details open>
<summary><b>👥 Client & Account Management</b></summary>

- Add new bank clients and create account records.
- Display the registered clients list.
- Find a client using an account number.
- Update existing client information.
- Delete client records.
- Check whether an account number already exists.
- Store client details and account balances in a local data file.
- Validate important input before saving records.

</details>

<details>
<summary><b>💸 Banking Transactions</b></summary>

- **Deposit:** Add funds to a client's account.
- **Withdraw:** Withdraw funds while checking the available balance.
- **Transfer:** Transfer funds between two client accounts.
- **Total Balances:** Display the combined balances of client accounts.
- Validate transaction amounts and available balances.
- Prevent transfers to the same account.
- Save updated account records to local storage.

</details>

<details>
<summary><b>🧾 Transfer History & Activity Logs</b></summary>

The transfer log stores information about transfers, including:

- Transfer date and time.
- Source account number.
- Destination account number.
- Transfer amount.
- Source balance after the transfer.
- Destination balance after the transfer.
- Username associated with the operation.

The application also includes a login-register screen for reviewing recorded login activity.

</details>

<details>
<summary><b>🔐 User Management & Permission System</b></summary>

- Login using a username and password.
- Add, list, find, update, and delete system users.
- Assign permissions to individual users.
- Check permissions before opening protected application sections.
- Support full-access permissions.
- Record successful login activity.
- Limit repeated failed login attempts.

Permissions cover application areas such as:

- Listing, adding, deleting, updating, and finding clients.
- Banking transactions.
- Managing users.
- Viewing the login register.
- Currency exchange.

</details>

<details>
<summary><b>💱 Currency Exchange</b></summary>

- Display the available currencies.
- Find a currency by country or currency code.
- Update a stored currency exchange rate.
- Convert an amount from one currency to another.
- Use USD as the base currency in the conversion process.
- Store currency information locally.

</details>

---

## <img src="https://img.shields.io/badge/03-ARCHITECTURE-0891B2?style=flat-square" alt="03 Architecture">

The project is divided into three main areas:

```text
Bank Management System/
│
├── Core/
│   ├── clsLoginScreen.h
│   ├── clsMainScreen.h
│   ├── clsScreen.h
│   └── Global.h
│
├── Models/
│   ├── clsBankClient.h
│   ├── clsCurrency.h
│   ├── clsPerson.h
│   └── clsUser.h
│
├── Screens/
│   ├── Client Actions/
│   │   ├── Client/
│   │   └── Transactions/
│   ├── Currency/
│   └── Users/
│
├── Bank System v04.cpp
└── Bank System v04.vcxproj
```

### Layer responsibilities

| Layer | Responsibility |
|:---|:---|
| 🧠 `Core/` | Login flow, main menu, shared screen behavior, and application-level state. |
| 🧩 `Models/` | Data models and operations for clients, users, people, and currencies. |
| 🖥️ `Screens/` | Console interfaces for client actions, transactions, user management, and currency operations. |

### Main model classes

<details>
<summary><b>clsPerson</b></summary>

A shared person model containing common personal information used by other models.

</details>

<details>
<summary><b>clsBankClient</b></summary>

Responsible for client account data and banking operations, including:

- Loading and saving client records.
- Finding and checking client accounts.
- Adding, updating, and deleting clients.
- Deposits and withdrawals.
- Transfers between accounts.
- Preparing and registering transfer-log records.

</details>

<details>
<summary><b>clsUser</b></summary>

Responsible for application users and access control, including:

- User records and lookup.
- Saving and updating users.
- Login-related operations.
- Permission checks.
- Login-register records.

</details>

<details>
<summary><b>clsCurrency</b></summary>

Responsible for currency data, lookup, exchange-rate updates, and currency conversion.

</details>

---

## <img src="https://img.shields.io/badge/04-DATA%20STORAGE-16A34A?style=flat-square" alt="04 Data Storage">

The application uses text files to persist information locally.

| Data file | Purpose |
|:---|:---|
| `Clients.txt` | Client and account records. |
| `Users.txt` | Application user records. |
| `TransferLog.txt` | Transfer history. |
| `LoginRegister.txt` | Login activity records. |
| `Currencies.txt` | Currency names, codes, countries, and exchange rates. |

Records are serialized into text lines and parsed back into objects when the application loads its data.

> **Important:** The current source contains machine-specific absolute Windows paths in some file operations. These paths must be updated before the project can run on another computer. Relative paths or configurable storage paths are recommended.

---

## <img src="https://img.shields.io/badge/05-TECHNOLOGIES%20%26%20CONCEPTS-DB2777?style=flat-square" alt="05 Technologies">

- **C++20**
- Object-Oriented Programming (OOP)
- Classes, objects, constructors, and inheritance
- Encapsulation and access control
- Static member functions
- Enums and permission flags
- STL containers such as `vector` and `string`
- File handling with `fstream` and `ifstream`
- Input validation
- Text-file serialization and parsing
- Separation of business/data logic from console screens
- Custom text transformation for selected stored values

---

## <img src="https://img.shields.io/badge/06-GETTING%20STARTED-F97316?style=flat-square" alt="06 Getting Started">

### Requirements

- Windows.
- Microsoft Visual Studio with the **Desktop development with C++** workload.
- A C++20-compatible MSVC toolset.
- The custom `MyLib` dependency used by the project.

### Build and run

1. Clone or download this repository.
2. Open the `.sln` solution or `.vcxproj` project in Visual Studio.
3. Configure the custom `MyLib` dependency on your computer.
4. Update machine-specific file paths used by the data-loading and data-saving functions.
5. Select the desired build configuration and platform.
6. Build the project.
7. Run the application.

### Dependency configuration

The Visual Studio project currently references:

- Include directory: `C:\MyLib`
- Library dependency: `MyLib.lib`

These are local project settings, not portable paths. You must provide the dependency and configure its include and library directories on your machine. The dependency is not bundled as a self-contained, portable package in this repository.

---

## <img src="https://img.shields.io/badge/07-SECURITY%20NOTICE-E11D48?style=flat-square" alt="07 Security Notice">

This is an educational project. Please keep the following limitations in mind:

- The current code uses a custom reversible transformation for selected PIN/password values. This is **not** secure password hashing or modern encryption.
- Do not use real customer information, real account credentials, or sensitive personal data.
- Do not publish personal data files or populated login and transfer logs.
- Use fictional sample records when sharing the project.
- A real banking application would require secure password hashing with salts, robust authorization, protected storage, reliable transaction handling, auditing, and extensive testing.

---

## <img src="https://img.shields.io/badge/08-FUTURE%20IMPROVEMENTS-9333EA?style=flat-square" alt="08 Future Improvements">

Possible areas for future development:

- Replace machine-specific absolute paths with portable, configurable paths.
- Separate file persistence behind a dedicated data-access layer.
- Replace text-file storage with a database.
- Add unit and integration tests.
- Improve error handling and recovery from failed file operations.
- Replace reversible password transformations with a standard password-hashing algorithm.
- Make transfers atomic so a partial failure cannot leave account balances inconsistent.
- Add a graphical user interface.

---

## <img src="https://img.shields.io/badge/09-PROJECT%20PURPOSE-0EA5E9?style=flat-square" alt="09 Project Purpose">

This project was built as a practical exercise in applying C++ and OOP concepts to a larger, integrated application.

Rather than focusing on isolated exercises, it combines multiple related subsystems and provides hands-on experience with:

- Designing classes and responsibilities.
- Organizing a multi-file C++ project.
- Applying encapsulation and inheritance.
- Validating user input.
- Reading and writing persistent data.
- Managing permissions and application access.
- Implementing operations that update multiple records.
- Separating application logic from console presentation.

---

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:6C2BD9,50:14213D,100:050816&height=120&section=footer" width="100%" alt="Decorative footer">

**BANK MANAGEMENT SYSTEM — UNLIMITED EDITION**

<sub>Built with C++20 • Driven by curiosity • Made for learning</sub>

</div>

