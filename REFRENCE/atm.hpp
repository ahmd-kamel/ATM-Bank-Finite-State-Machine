#ifndef ATM_HPP_
#define ATM_HPP_

class ATM {
private:
    struct Account 
    {
        std::string accountNumber;
        std::string pin;
        double balance;
        bool isLocked = false;
    };

    std::unordered_map<std::string, Account> accounts;
    Account* currentAccount = nullptr;
    std::map<std::string, std::string> translations;

    void loadTranslations(const std::string& language) 
    {
        translations.clear();
        if (language == "English") 
        {
            translations["welcome"] = "Welcome to the ATM";
            translations["enter_account"] = "Please insert your card: ";
            translations["enter_pin"] = "Enter your PIN: ";
            translations["invalid_account"] = "Invalid account number.";
            translations["invalid_pin"] = "Invalid PIN.";
            translations["card_locked"] = "Your Card has been locked due to too many incorrect PIN attempts.";
            translations["main_menu"] = "\nATM Main Menu:\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Change PIN\n5. Exit\nSelect an option: ";
            translations["balance"] = "Your current balance is: $";
            translations["deposit_prompt"] = "Enter amount to deposit: $";
            translations["deposit_success"] = " has been deposited to your account.";
            translations["invalid_amount"] = "Invalid amount.";
            translations["withdraw_options"] = "Select withdraw type: \n1. Regular\n2. Fast\nSelect an option: ";
            translations["withdraw_prompt"] = "Enter amount to withdraw: $";
            translations["withdraw_fast"] = "Fast Withdraw Menu:\n1. 100\n2. 200\n3. 500\n4. 1000\n5. 5000\n6. 8000\nSelect an option: ";
            translations["receipt_option"] = "Do you want a receipt: \n1. Yes\n2. No\nSelect an option: ";
            translations["withdraw_success"] = " has been withdrawn from your account.";
            translations["insufficient_balance"] = "Insufficient balance or invalid amount.";
            translations["goodbye"] = "Thank you for using the ATM. Goodbye!";
            translations["invalid_option"] = "Invalid option. Please try again.";
        } 
        else if (language == "Spanish") 
        {
            translations["welcome"] = "Bienvenido al cajero automático";
            translations["enter_account"] = "Por favor inserte su tarjeta: ";
            translations["enter_pin"] = "Ingrese su PIN: ";
            translations["invalid_account"] = "Número de cuenta inválido.";
            translations["invalid_pin"] = "PIN inválido.";
            translations["card_locked"] = "Su cuenta ha sido bloqueada debido a demasiados intentos incorrectos de PIN.";
            translations["main_menu"] = "\nMenú principal del cajero automático:\n1. Consultar saldo\n2. Depositar dinero\n3. Retirar dinero\n4. Cambiar PIN\n5. Salir\nSeleccione una opción: ";
            translations["balance"] = "Su saldo actual es: $";
            translations["deposit_prompt"] = "Ingrese el monto a depositar: $";
            translations["deposit_success"] = " ha sido depositado en su cuenta.";
            translations["invalid_amount"] = "Monto inválido.";
            translations["withdraw_options"] = "Seleccione el tipo de retiro:\n1. Regular\n 2. Rápido\n Seleccione una opción: ";
            translations["withdraw_prompt"] = "Ingrese el monto a retirar: $";
            translations["withdraw_fast"] = "Menú de retiro rápido:\n1. 100\n2. 200\n3. 500\n4. 1000\n5. 5000\n6. 8000\nSeleccione una opción: ";
            translations["withdraw_success"] = " ha sido retirado de su cuenta.";
            translations["insufficient_balance"] = "Saldo insuficiente o monto inválido.";
            translations["goodbye"] = "¡Gracias por usar el cajero automático! ¡Adiós!";
            translations["invalid_option"] = "Opción inválida. Inténtalo de nuevo.";
        }
    }

    void displayMainMenu() 
    {
        std::cout << translations["main_menu"];
    }

    void checkBalance(bool *exit) 
    {
        int attemps = 0;
        L1:
        std::cout << translations["balance"] << currentAccount->balance << "\n";
        int option = -1;
        std::cout << translations["receipt_option"];
        std::cin >> option;
        if (option == 1)
        {
            *exit = true;
            std::cout << "Please wait for receipt\n";
            std::cout << translations["goodbye"] << std::endl;

        }
        else if (option == 2)
        {
            *exit = true;
            std::cout << "Please Wait for your card." << std::endl;
            std::cout << translations["goodbye"] << std::endl;
        }
        else
        {
            std::cout << translations["invalid_option"] << std::endl;
            std::cout << std::endl;
            if (attemps < 2)
            {
                attemps++;
                goto L1;
            }
            else
            {
                *exit = true;
                std::cout << "Wait for the card. Please try again later\n";
            }
        }
    }

    void depositMoney(bool *exit) 
    {
        int attemps = 0;
        L2:
        double amount = 0;
        std::cout << translations["deposit_prompt"];
        std::cin >> amount;
        if (amount > 0)
        {
            std::cout << "You have deposit = " << amount << "$" << std::endl;
            std::cout << "Deposit Options:\n1. Confirm\n2. Reject\nSelect an option : ";
            int options = -1;
            std::cin >> options;
            if (options == 1)
            {
                currentAccount->balance += amount;
                std::cout << "$" << amount << translations["deposit_success"] << "\n";
                std::cout << "Another Operations:\n1. Yes\n2. No\nSelect an option : ";
                int ops = -1;
                std::cin >> ops;
                if (ops == 1)
                {
                    return;
                }
                else
                {
                    *exit = true;
                    std::cout << translations["goodbye"] << std::endl;
                    return;
                }
            }
            else if(options == 2)
            {
                *exit = true;
                std::cout << "Please wait for your money" << std::endl;
                return;
            }
            else
            {
                if (attemps < 2)
                {
                    attemps++;
                    goto L2;
                }
                else
                {
                    *exit = true;
                    std::cout << "Wait for the card. Please try again later\n";
                }
            }
        }
        else
        {
            *exit = true;
            std::cout << translations["invalid_amount"] << "\n";
        }
    }

    void changePin(std::string accountNumber, bool *exit) {
        int attemps = 0;
        L2:
        std::string first_pin, second_pin;
        std::cout << "Please enter new pin: " << std::endl;
        std::cin >> first_pin;
        std::cout << "Please enter new pin again: " << std::endl;
        std::cin >> second_pin;
        if(first_pin.compare(second_pin) == 0)
        {
            *exit = true;
            accounts[accountNumber] = {accountNumber, second_pin, accounts[accountNumber].balance};
            std::cout << translations["goodbye"] << std::endl;
        }
        else
        {
            if (attemps < 2)
            {
                attemps++;
                goto L2;
            }
            else
            {
                *exit = true;
                std::cout << "Wait for the card. Please try again later\n";
            }
        }

    }

    void withdrawMoney(bool *exit) {
        int attemps = 0;
        L3:
        double amount = 0;
        std::cout << translations["withdraw_options"];
        int choice;
        std::cin >> choice;
        if(choice == 1)
        {
            std::cout << translations["withdraw_prompt"];
            std::cin >> amount;
        }
        else if(choice == 2)
        {
            int fast_opt = 0;
            std::cout << translations["withdraw_fast"];
            std::cin >> fast_opt;
            switch (fast_opt) 
            {
                case 1:
                    amount = 100;
                    break;
                case 2:
                    amount = 200;
                    break;
                case 3:
                    amount = 500;
                    break;
                case 4:
                    amount = 1000;
                    break;
                case 5:
                    amount = 5000;
                    break;
                case 6:
                    amount = 8000;
                    break;
                default:
                    std::cout << translations["invalid_option"] << "\n";
            }
        }
        else
        {
            std::cout << translations["invalid_option"] << std::endl;
            std::cout << std::endl;
            if (attemps < 2)
            {
                attemps++;
                goto L3;
            }
            else
            {
                *exit = true;
                std::cout << "Wait for the card. Please try again later\n";
            }
        }

        if (amount > 0 && amount <= currentAccount->balance) 
        {
            std::cout << "$" << amount << translations["withdraw_success"] << "\n";
            currentAccount->balance -= amount;
            int option = 0;
            int attemps_2 = 0;
        L4:
            std::cout << translations["receipt_option"];
            std::cin >> option;
            if (option == 1)
            {
                *exit = true;
                std::cout << "Please wait for receipt\n";
            }
            else if (option == 2)
            {
                *exit = true;
                return;
            }
            else
            {
                std::cout << translations["invalid_option"] << std::endl;
                std::cout << std::endl;
                if (attemps_2 < 2)
                {
                    attemps_2++;
                    goto L4;
                }
                else
                {
                    *exit = true;
                    std::cout << "Wait for the card. Please try again later\n";
                }
            }

        } 
        else 
        {
            *exit = true;
            std::cout << translations["insufficient_balance"] << "\n";
        }
    }

public:
    ATM() 
    {
        // Adding some sample accounts
        accounts["123456"] = {"123456", "1111", 500.0};
        accounts["654321"] = {"654321", "2222", 1000.0};
    }

    void run() 
    {
        std::string language = "English";
        loadTranslations(language);


        std::string accountNumber, pin;
        std::cout << translations["welcome"] << "\n";
        std::cout << translations["enter_account"];
        std::cin >> accountNumber;

        auto it = accounts.find(accountNumber);
        if (it != accounts.end()) 
        {
            std::cout << "Select your language / Seleccione su idioma (English/Spanish): ";
            std::cin >> language;
            loadTranslations(language);

            if (it->second.isLocked) 
            {
                std::cout << translations["card_locked"] << "\n";
                return;
            }

            int pinAttempts = 0;
            while (pinAttempts < 3) 
            {
                std::cout << translations["enter_pin"];
                std::cin >> pin;
                if (it->second.pin == pin) 
                {
                    currentAccount = &it->second;
                    bool exit = false;
                    while (!exit) 
                    {
                        displayMainMenu();
                        int choice;
                        std::cin >> choice;
                        switch (choice) 
                        {
                            case 1:
                                checkBalance(&exit);
                                break;
                            case 2:
                                depositMoney(&exit);
                                break;
                            case 3:
                                withdrawMoney(&exit);
                                break;
                            case 4:
                                changePin(accountNumber, &exit);
                                break;
                            case 5:
                                exit = true;
                                std::cout << translations["goodbye"] << "\n";
                                break;
                            default:
                                std::cout << translations["invalid_option"] << "\n";
                        }
                    }
                    return;
                } 
                else 
                {
                    pinAttempts++;
                    if (pinAttempts == 3) 
                    {
                        it->second.isLocked = true;
                        std::cout << translations["card_locked"] << "\n";
                        return;
                    } 
                    else 
                    {
                        std::cout << translations["invalid_pin"] << "\n";
                    }
                }
            }
        } 
        else 
        {
            std::cout << translations["invalid_account"] << "\n";
        }
    }
};

#endif