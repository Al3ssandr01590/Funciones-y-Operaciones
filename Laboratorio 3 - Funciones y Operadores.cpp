#include <iostream>

// Funcion para calcular la potencia
int calcularPotencia(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else if (exponente < 0) {
        return 0; // Manejar casos donde el exponente sea cero o negativo
    } else {
        return base * calcularPotencia(base, exponente - 1);
    }
}

// Funcion para determinar si un numero es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

// Funcion para determinar si un ano es bisiesto
bool esBisiesto(int anio) {
    if (anio % 4 == 0) {
        if (anio % 100 == 0) {
            if (anio % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    int opcion;
    do {
        std::cout << "Menu de opciones:\n";
        std::cout << "1. Operaciones aritmeticas\n";
        std::cout << "2. Calcular potencia\n";
        std::cout << "3. Determinar si un numero es primo\n";
        std::cout << "4. Determinar si un ano es bisiesto\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                int num1, num2;
                char operacion;
                double resultado;

                std::cout << "Ingrese el primer numero: ";
                std::cin >> num1;
                std::cout << "Ingrese el segundo numero: ";
                std::cin >> num2;
                std::cout << "Ingrese la operacion (+, -, *, /): ";
                std::cin >> operacion;

                switch (operacion) {
                    case '+':
                        resultado = num1 + num2;
                        break;
                    case '-':
                        resultado = num1 - num2;
                        break;
                    case '*':
                        resultado = num1 * num2;
                        break;
                    case '/':
                        if (num2 != 0) {
                            resultado = static_cast<double>(num1) / num2;
                        } else {
                            std::cout << "Error: Division por cero\n";
                            break;
                        }
                    default:
                        std::cout << "Operacion no valida\n";
                        break;
                }

                std::cout << "Resultado: " << resultado << "\n";
                break;
            }
            case 2: {
                int base, exponente;
                std::cout << "Ingrese la base: ";
                std::cin >> base;
                std::cout << "Ingrese el exponente: ";
                std::cin >> exponente;
                int resultado = calcularPotencia(base, exponente);
                std::cout << "Resultado: " << resultado << "\n";
                break;
            }
            case 3: {
                int numero;
                std::cout << "Ingrese un numero: ";
                std::cin >> numero;
                if (esPrimo(numero)) {
                    std::cout << numero << " es primo.\n";
                } else {
                    std::cout << numero << " no es primo.\n";
                }
                break;
            }
            case 4: {
                int anio;
                std::cout << "Ingrese un ano: ";
                std::cin >> anio;
                if (esBisiesto(anio)) {
                    std::cout << anio << " es un ano bisiesto.\n";
                } else {
                    std::cout << anio << " no es un ano bisiesto.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default:
                std::cout << "Opcion no valida. Por favor, ingrese una opcion valida.\n";
        }
    } while (opcion != 5);

    return 0;
}
