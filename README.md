<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:050816,45:14213D,100:6C2BD9&height=210&section=header&text=BANK%20MANAGEMENT%20SYSTEM&fontSize=35&fontColor=FFFFFF&animation=fadeIn&fontAlignY=35&desc=UNLIMITED%20EDITION%20%E2%80%A2%20C%2B%2B20&descSize=18&descAlignY=58" width="100%">

<a href="https://readme-typing-svg.demolab.com">
<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=19&pause=1000&color=38BDF8&center=true&vCenter=true&width=750&lines=More+than+a+CRUD+application;Client+Management+%7C+Banking+Transactions;Authentication+%7C+Access+Control;Currency+Exchange+%7C+Activity+Logs;Built+with+C%2B%2B20+and+OOP">
</a>

<br>

<img src="https://img.shields.io/badge/LANGUAGE-C%2B%2B20-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">
<img src="https://img.shields.io/badge/PARADIGM-OBJECT--ORIENTED-7C3AED?style=for-the-badge">
<img src="https://img.shields.io/badge/PLATFORM-WINDOWS-0078D6?style=for-the-badge&logo=windows&logoColor=white">
<img src="https://img.shields.io/badge/IDE-VISUAL%20STUDIO-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white">
<img src="https://img.shields.io/badge/TYPE-EDUCATIONAL%20PROJECT-F59E0B?style=for-the-badge">

<br><br>

**A feature-rich C++ console banking application — designed to bring multiple banking operations together in one OOP-based system.**

<a href="#-overview"><img src="https://img.shields.io/badge/OVERVIEW-2563EB?style=flat-square"></a>
<a href="#-features"><img src="https://img.shields.io/badge/FEATURES-7C3AED?style=flat-square"></a>
<a href="#-architecture"><img src="https://img.shields.io/badge/ARCHITECTURE-0891B2?style=flat-square"></a>
<a href="#-getting-started"><img src="https://img.shields.io/badge/SETUP-16A34A?style=flat-square"></a>
<a href="#-security-notice"><img src="https://img.shields.io/badge/SECURITY-E11D48?style=flat-square"></a>

</div>

---

## <img src="https://img.shields.io/badge/01-OVERVIEW-2563EB?style=for-the-badge">

**Bank Management System — Unlimited Edition** is a C++ console application that simulates several operations found in a small banking environment.

This project goes beyond a basic CRUD application. It combines several connected subsystems:

<p align="center">
<img src="https://img.shields.io/badge/CLIENT%20MANAGEMENT-2563EB?style=for-the-badge">
<img src="https://img.shields.io/badge/TRANSACTIONS-16A34A?style=for-the-badge">
<img src="https://img.shields.io/badge/USER%20AUTHENTICATION-7C3AED?style=for-the-badge">
<img src="https://img.shields.io/badge/PERMISSIONS-DB2777?style=for-the-badge">
<img src="https://img.shields.io/badge/CURRENCY%20EXCHANGE-D97706?style=for-the-badge">
</p>

The code is organized into separate **Core**, **Models**, and **Screens** areas. This separation helps keep application flow, data/business operations, and console interaction responsibilities distinct.

The application uses local text files to persist records between runs.

> [!IMPORTANT]
> **Educational project — not production banking software.** This project is intended for learning and demonstrating C++ and OOP concepts. It does not provide the security, reliability, regulatory compliance, or transactional guarantees required by a real banking system.

---

## <img src="https://img.shields.io/badge/02-FEATURES-7C3AED?style=for-the-badge">

<details open>
<summary><img src="https://img.shields.io/badge/CLIENTS-2563EB?style=flat-square"> <b>👥 Client & Account Management</b></summary>

- <img src="https://img.shields.io/badge/ADD-16A34A?style=flat-square"> Add new bank clients and create account records.
- <img src="https://img.shields.io/badge/LIST-0891B2?style=flat-square"> Display the registered clients list.
- <img src="https://img.shields.io/badge/FIND-7C3AED?style=flat-square"> Find a client using an account number.
- <img src="https://img.shields.io/badge/UPDATE-D97706?style=flat-square"> Update existing client information.
- <img src="https://img.shields.io/badge/DELETE-E11D48?style=flat-square"> Delete client records.
- <img src="https://img.shields.io/badge/VALIDATION-0F766E?style=flat-square"> Check account-number uniqueness and validate important input.
- <img src="https://img.shields.io/badge/STORAGE-475569?style=flat-square"> Store client details and account balances locally.

</details>

<details>
<summary><img src="https://img.shields.io/badge/TRANSACTIONS-16A34A?style=flat-square"> <b>💸 Banking Transactions</b></summary>

- <img src="https://img.shields.io/badge/DEPOSIT-16A34A?style=flat-square"> **Deposit:** Add funds to a client's account.
- <img src="https://img.shields.io/badge/WITHDRAW-D97706?style=flat-square"> **Withdraw:** Withdraw funds while checking the available balance.
- <img src="https://img.shields.io/badge/TRANSFER-2563EB?style=flat-square"> **Transfer:** Transfer funds between two client accounts.
- <img src="https://img.shields.io/badge/TOTAL%20BALANCES-7C3AED?style=flat-square"> **Total Balances:** Display the combined balances of client accounts.
- <img src="https://img.shields.io/badge/CHECKS-E11D48?style=flat-square"> Validate transaction amounts, available balances, and destination accounts.

</details>

<details>
<summary><img src="https://img.shields.io/badge/AUDIT%20LOGS-0891B2?style=flat-square"> <b>🧾 Transfer History & Activity Logs</b></summary>

The transfer log stores details about transfers, including:

- <img src="https://img.shields.io/badge/TIMESTAMP-64748B?style=flat-square"> Transfer date and time.
- <img src="https://img.shields.io/badge/SOURCE-2563EB?style=flat-square"> Source account number.
- <img src="https://img.shields.io/badge/DESTINATION-7C3AED?style=flat-square"> Destination account number.
- <img src="https://img.shields.io/badge/AMOUNT-16A34A?style=flat-square"> Transfer amount.
- <img src="https://img.shields.io/badge/BALANCE-D97706?style=flat-square"> Source and destination balances after the transfer.
- <img src="https://img.shields.io/badge/USER-DB2777?style=flat-square"> Username associated with the operation.

The application also includes a login-register screen for reviewing recorded login activity.

</details>

<details>
<summary><img src="https://img.shields.io/badge/ACCESS%20CONTROL-DB2777?style=flat-square"> <b>🔐 User Management & Permission System</b></summary>

- Authenticate users through a login screen.
- Add, list, find, update, and delete system users.
- Assign permissions to individual users.
- Check permissions before opening protected application sections.
- Support full-access permissions.
- Record successful login activity.
- Limit repeated failed login attempts.

**Permission-controlled areas include:**

<p>
<img src="https://img.shields.io/badge/CLIENT%20OPERATIONS-2563EB?style=flat-square">
<img src="https://img.shields.io/badge/TRANSACTIONS-16A34A?style=flat-square">
<img src="https://img.shields.io/badge/USER%20MANAGEMENT-7C3AED?style=flat-square">
<img src="https://img.shields.io/badge/LOGIN%20REGISTER-D97706?style=flat-square">
<img src="https://img.shields.io/badge/CURRENCY-0891B2?style=flat-square">
</p>

</details>

<details>
<summary><img src="https://img.shields.io/badge/CURRENCY-D97706?style=flat-square"> <b>💱 Currency Exchange</b></summary>

- Display the available currencies.
- Find a currency by country or currency code.
- Update a stored currency exchange rate.
- Convert an amount from one currency to another.
- Use USD as the base currency in the conversion process.
- Store currency information locally.

</details>

---

## <img src="https://img.shields.io/badge/03-ARCHITECTURE-0891B2?style=for-the-badge">

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


Layer responsibilities
Layer	Responsibility
🧠 Core/	Login flow, main menu, shared screen behavior, and application-level state.
🧩 Models/	Data models and operations for clients, users, people, and currencies.
🖥️ Screens/	Console interfaces for client actions, transactions, user management, and currency operations.

Main model classes
