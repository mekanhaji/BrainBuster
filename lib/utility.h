#ifndef UTILITY_H
#define UTILITY_H

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

void clear_input_buffer();
/**
 * @brief Clear the screen
 */
void clear_screen();

#endif // UTILITY_H