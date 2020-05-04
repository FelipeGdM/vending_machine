/**
 * @file utils.h
 * @author Time Comp
 * @brief Mathematic utilitary functions globally available.
 * @version 1.0
 * @date 01/2020
 *
 * @see https://github.com/ThundeRatz/Tracer
 */

#ifndef __UTILS_H__
#define __UTILS_H__


/*****************************************
 * Public Macros
 *****************************************/

/**
 * @brief Imprime na tela uma quantia de dinheiro formatada com R$
 * 
 */
#define dinheiro_print(dinheiro) printf("R$ %hhu.%02hhu", dinheiro.reais, dinheiro.centavos)

/**
 * @brief Imprime na tela uma quantia de dinheiro a partir de um ponteiro 
 * formatada com R$
 */
#define p_dinheiro_print(dinheiro) printf("R$ %hhu.%02hhu", dinheiro->reais, dinheiro->centavos)

/**
 * @brief Returns x absolute value.
 */
#define abs(x) ((x) > 0 ? (x) : -(x))

/**
 * @brief Returns x signal
 */
#define sig(x) ((x) == 0 ? (0) : ((x) > 0 ? (1) : -(1)))

/**
 * @brief Returns maximum value between x and y.
 */
#define max(x, y) ((x) > (y) ? (x) : (y))

/**
 * @brief Returns minimum value between x and y.
 */
#define min(x, y) ((x) < (y) ? (x) : (y))

/**
 * @brief Constrains v between x and y, returning at least x and at most y.
 */
#define constrain(v, x, y) ((v) < (x) ? (x) : ((v) > (y) ? (y) : (v)))

/**
 * @brief Returns the length of statically defined arrays.
 */
#define len(arr) (sizeof(arr) / sizeof(arr[0]))

/*****************************************
 * Public Function Bodies
 *****************************************/

/**
 * @brief Maps an integer value from one scale to another.
 *
 * @param former_value Value in former scale.
 * @param former_min   Former scale minimum value.
 * @param former_max   Former scale maximum value.
 * @param new_min      New scale minimum value.
 * @param new_max      New scale maximum value.
 *
 * @return Value in new scale
 */
inline double map(double former_value, double former_min, double former_max, double new_min, double new_max) {
    double new_value;

    new_value = (former_value - former_min) * (new_max - new_min);
    new_value /= (former_max - former_min);
    new_value += new_min;

    return new_value;
}

#endif  // __UTILS_H__
