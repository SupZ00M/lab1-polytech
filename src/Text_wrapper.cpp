#include "Text_wrapper.hpp"
#include <iostream>
#include <stdexcept>

TextWrapper::TextWrapper(const MyString& str, int width)
    : input(str), max_width(width), current_pos(0), current_line_len(0) {
    if (width <= 0) throw std::runtime_error("TextWrapper.__init__: width <= 0");
}

bool TextWrapper::is_end_of_text() {
    return current_pos >= input.get_length();
}

void TextWrapper::skip_spaces() {
    while (!is_end_of_text() && input.get(current_pos) == ' ') {
        current_pos++;
    }
}

int TextWrapper::get_word_length() {
    int len = 0;
    while ((current_pos + len) < input.get_length() && input.get(current_pos + len) != ' ') {
        len++;
    }
    return len;
}

bool TextWrapper::can_fit(int word_len) {
    int space = (current_line_len == 0) ? 0 : 1;
    return (current_line_len + space + word_len) <= max_width;
}

void TextWrapper::start_new_line() {
    std::cout << "\n";
    current_line_len = 0;
}

void TextWrapper::print_word(int len) {
    if (current_line_len > 0) {
        std::cout << " ";
        current_line_len++;
    }
    for (int i = 0; i < len; ++i) {
        std::cout << input.get(current_pos + i);
    }
    current_line_len += len;
    current_pos += len;
}

void TextWrapper::print_wrapped() {
    current_pos = 0;
    current_line_len = 0;

    while (!is_end_of_text()) {
        skip_spaces();
        if (is_end_of_text()) {
            break;
        }

        int word_len = get_word_length();

        if (word_len >= max_width) {
            if (current_line_len > 0) {
                 start_new_line();
            }
            print_word(word_len);
            start_new_line();
        }
        else if (can_fit(word_len)) {
            print_word(word_len);
        }
        else {
            start_new_line();
            print_word(word_len);
        }
    }
    std::cout << "\n";
}