🏦 نظام إدارة بنك (C++ OOP Console App / تطبيق كونسول بلغة C++ مع OOP)
📌 نظرة عامة | Overview

النظام ده بيحاكي عمل البنوك بشكل مبسط باستخدام الكونسول، وبيوفر أدوات لإدارة العملاء، المعاملات المالية، المستخدمين، وكمان العملات.
This system simulates basic banking operations using a console interface, providing tools to manage clients, financial transactions, users, and currencies.

✨ المميزات | Features
👥 إدارة العملاء | Clients Management

إضافة، تعديل، حذف، عرض وبحث عن العملاء.

Add, update, delete, list, and search for clients.

💳 المعاملات المالية | Transactions

إيداع، سحب، تحويل بين الحسابات، وسجل العمليات.

Deposit, withdraw, transfer between accounts, and view transaction history.

🔐 إدارة المستخدمين | Users Management

إضافة مستخدم جديد، تعديل بياناته، حذفه، وعرض المستخدمين.

Add new users, update user data, delete users, and list all users.

💱 إدارة العملات | Currencies Management

عرض جميع العملات المتاحة.

تعديل سعر الصرف لأي عملة.

تحويل من عملة إلى أخرى (مثال: 100 USD → 3100 EGP).

View all available currencies.

Edit exchange rates.

Convert from one currency to another (e.g., 100 USD → 3100 EGP).

📜 تسجيل الدخول والخروج | Login & Logout

نظام تسجيل دخول آمن بكلمة مرور.

سجل لعمليات الدخول والخروج.

Secure login system with password.

Login and logout activity history.

🖥 القائمة الرئيسية | Main Menu
[1] عرض العملاء | Show Clients
[2] إضافة عميل جديد | Add New Client
[3] حذف عميل | Delete Client
[4] تعديل بيانات عميل | Update Client Info
[5] البحث عن عميل | Find Client
[6] العمليات المالية | Transactions
[7] إدارة المستخدمين | Manage Users
[8] إدارة العملات 💱 | Manage Currencies
[9] سجل تسجيل الدخول | Login Register
[10] تسجيل الخروج | Logout

🧩 البنية الداخلية | Internal Structure

Client Class → يمثل العميل وبياناته. | Represents client and account details.

Transaction Class → يمثل العمليات المالية. | Represents financial transactions.

Currency Class → يمثل العملات وأسعار الصرف. | Represents currencies and exchange rates.

User Class → يمثل المستخدم وصلاحياته. | Represents users and permissions.

BankSystem Class → النظام الأساسي اللي بيربط كل المكونات. | Main system that integrates all components.

📖 مثال تشغيل عملي | Example Scenario

تسجيل الدخول كمستخدم. | Login as a user.

إضافة عميل جديد برقم حساب ورصيد. | Add a new client with account number and balance.

عمل إيداع 2000 جنيه في الحساب. | Deposit 2000 into the account.

الدخول إلى إدارة العملات وتحويل 100 دولار إلى جنيه مصري. | Go to currencies management and convert 100 USD to EGP.

تسجيل الخروج من النظام. | Logout from the system.

🎯 الهدف من المشروع | Purpose

التدريب على مبادئ OOP (التغليف، الوراثة، التعددية).

تنظيم الكود بشكل احترافي وسهل التطوير.

محاكاة نظام بنكي بشكل مبسط.

إضافة إدارة العملات لتقريب النظام أكثر للواقع.

Practice OOP principles (Encapsulation, Inheritance, Polymorphism).

Write clean, maintainable, and modular code.

Simulate a real-world banking system in a simplified way.

Enhance realism by including currency management.
