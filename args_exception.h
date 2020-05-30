#include <exception>

/* Excepcion lanzada cuando la cola bloqueante se
 * encuentra cerrada.
 */
class ArgsException : public std::exception {
public:
    const char* what() const throw() {
        return "Error: argumentos invalidos.";
    }
};