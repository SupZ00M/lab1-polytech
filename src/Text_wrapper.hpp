#include "My_string.hpp"

class TextWrapper {
private:
    const MyString& input;
    int max_width;
    int current_pos;
    int current_line_len;

    bool is_end_of_text();
    bool can_fit(int word_len);
    void skip_spaces();
    int get_word_length();
    void print_word(int len);
    void start_new_line();

public:
    TextWrapper(const MyString& str, int width);
    void print_wrapped();
};