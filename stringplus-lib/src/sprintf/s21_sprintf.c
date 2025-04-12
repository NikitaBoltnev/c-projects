#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  s21_size_t check = 0;
  if (str != s21_NULL && format != s21_NULL) {
    int checkSpecifier = 0;
    Flags flag = {0};
    va_list factor;
    va_start(factor, format);
    str[0] = '\0';
    unsigned long num = 0;
    for (const char *c = format; *c != '\0'; c++) {
      if (*c == '%' && checkSpecifier == 0) {
        zeroingFlags(&flag);
        checkSpecifier = 1;
      } else if (checkSpecifier > 0 && (*c == '-' || *c == '+' || *c == ' ')) {
        readFlags(&flag, c);
      } else if (checkSpecifier == 1 && (*c >= '0' && *c <= '9')) {
        flag.width = readIntegerFromStr(&c);
        c--;
        checkSpecifier = 2;
      } else if (*c == '.' && checkSpecifier > 0 && checkSpecifier < 3) {
        c++;
        flag.accuracy = readIntegerFromStr(&c);
        c--;
        checkSpecifier = 3;
      } else if (checkSpecifier > 0 && checkSpecifier < 4 &&
                 (*c == 'h' || *c == 'l')) {
        readLength(&flag, c);
        checkSpecifier = 4;
      } else if (checkSpecifier > 0 && (*c == 'c' || *c == 'd' || *c == 'f' ||
                                        *c == 's' || *c == 'u' || *c == '%')) {
        if (*c == 'f' && flag.accuracy == -1) {
          flag.accuracy = 6;
        }

        switch (*c) {
          case '%':

            check = fillingStringWithChar(&str, '%', check, &flag);

            break;

          case 'c':
            check =
                fillingStringWithChar(&str, va_arg(factor, int), check, &flag);

            break;

          case 'd': {
            long long number = 0;
            if (flag.length == 'h') {
              number = (short)va_arg(factor, int);
            } else if (flag.length == 'l') {
              number = va_arg(factor, long);
            } else {
              number = va_arg(factor, int);
            }

            check = processing_flags(number, 10, &flag, check, &str);

            break;
          }

          case 'f':
            if (flag.length == 'l') {
              check = processingFlagsForF(&flag, (double)va_arg(factor, double),
                                          &str, check);
            } else {
              check = processingFlagsForF(&flag, va_arg(factor, double), &str,
                                          check);
            }
            break;

          case 's':
            check = spec_s(&str, va_arg(factor, char *), check, &flag);
            break;

          case 'u':

            if (flag.length == 'l') {
              num = va_arg(factor, unsigned long);
            } else {
              (num = (unsigned int)va_arg(factor, unsigned int));
            }
            check = processingFlagsForU(num, &flag, &str, check);

            break;
        }
        checkSpecifier = 0;
      } else if (checkSpecifier == 0) {
        str[check++] = *c;
      } else {
        s21_errors_sprintf(&str, &flag, c, &check);
        checkSpecifier = 0;
      }
    }
    va_end(factor);
    str[check] = '\0';
  }

  return check;
}

void readFlags(Flags *flag, const char *tempC) {
  if (*tempC == '-') {
    flag->flagMinus = 1;
  }

  if (*tempC == '+') {
    flag->flagPlus = 1;
  }

  if (*tempC == ' ') {
    flag->flagSpace = 1;
  }
}

int readIntegerFromStr(const char **tempC) {
  int number = 0;
  while (**tempC >= '0' && **tempC <= '9') {
    number *= 10;
    number += (**tempC) - '0';
    (*tempC)++;
  }

  return number;
}

void readLength(Flags *flag, const char *tempC) {
  if (*tempC == 'h') {
    flag->length = 'h';
  } else if (*tempC == 'l') {
    flag->length = 'l';
  }
}

void zeroingFlags(Flags *flag) {
  s21_memset(flag, 0, sizeof(Flags));
  flag->accuracy = -1;
}

int fillingStringWithChar(char **res, char c, int check, Flags *flag) {
  if (*res != s21_NULL) {
    int width = flag->width;
    if (width > 1) {
      if (flag->flagMinus == 1) {
        (*res)[check++] = c;

        for (int i = 1; i < width; i++) {
          (*res)[check++] = ' ';
        }
      } else {
        for (int i = 1; i < width; i++) {
          (*res)[check++] = ' ';
        }
        (*res)[check++] = c;
      }
    } else {
      (*res)[check++] = c;
    }
    (*res)[check] = '\0';
  }
  return check;
}

int processing_flags(long long value, int base, Flags *flag, int check,
                     char **res) {
  char temp_num[1024] = {0};
  char *p = temp_num;
  bool is_negative = false;
  char sign_char = '\0';

  if (value < 0) {
    is_negative = true;
    value = -value;
  } else if (flag->flagPlus) {
    sign_char = '+';
  } else if (flag->flagSpace) {
    sign_char = ' ';
  }

  do {
    *p++ = "0123456789"[value % base];
    value /= base;
  } while (value);
  *p = '\0';
  reverse_string(temp_num);

  int num_len = s21_strlen(temp_num);

  if (flag->accuracy > num_len) {
    int zero_padding = flag->accuracy - num_len;
    for (int i = num_len - 1; i >= 0; i--) {
      temp_num[i + zero_padding] = temp_num[i];
    }
    for (int i = 0; i < zero_padding; i++) {
      temp_num[i] = '0';
    }
    num_len += zero_padding;
  }

  if (sign_char != '\0' || is_negative) {
    char sign = (is_negative) ? '-' : sign_char;
    for (int i = num_len - 1; i >= 0; i--) {
      temp_num[i + 1] = temp_num[i];
    }
    temp_num[0] = sign;
    num_len += 1;
  }

  if (flag->width > num_len) {
    int space_padding = flag->width - num_len;
    if (flag->flagMinus) {
      for (int i = 0; i < num_len; i++) {
        (*res)[check++] = temp_num[i];
      }
      for (int i = 0; i < space_padding; i++) {
        (*res)[check++] = ' ';
      }
    } else {
      for (int i = 0; i < space_padding; i++) {
        (*res)[check++] = ' ';
      }
      for (int i = 0; i < num_len; i++) {
        (*res)[check++] = temp_num[i];
      }
    }
  } else {
    for (int i = 0; i < num_len; i++) {
      (*res)[check++] = temp_num[i];
    }
  }

  return check;
}

void reverse_string(char *str) {
  char *begin = str;
  char *end = str;
  while (*end) {
    end++;
  }
  end--;
  while (begin < end) {
    char temp = *begin;
    *begin = *end;
    *end = temp;
    begin++;
    end--;
  }
}

int processingFlagsForU(unsigned long num, Flags *flag, char **res, int check) {
  char resTemp[1024] = {0};
  int digitCount = 0;
  unsigned long temp = num;
  if (num == 0) {
    resTemp[0] = '0';
    digitCount = 1;
  }
  while (temp != 0) {
    digitCount++;
    temp /= 10;
  }
  temp = num;
  for (int i = digitCount - 1; i >= 0; i--) {
    resTemp[i] = (temp % 10) + '0';
    temp /= 10;
  }
  resTemp[digitCount] = '\0';

  if (flag->accuracy >= 0 && flag->accuracy > digitCount) {
    int nulCount = 0;
    nulCount = flag->accuracy - digitCount;
    for (int i = digitCount; i >= 0; i--) {
      resTemp[i + nulCount] = resTemp[i];
    }
    for (int i = 0; i < nulCount; i++) {
      resTemp[i] = '0';
    }
    digitCount += nulCount;
  }

  if (flag->width > digitCount) {
    int tempWidth = 0;
    tempWidth = flag->width - digitCount;
    if (flag->flagMinus == 1) {
      for (int i = 0; i < digitCount; i++) {
        (*res)[check++] = resTemp[i];
      }
      for (int i = 0; i < tempWidth; i++) {
        (*res)[check++] = ' ';
      }
    } else {
      for (int i = 0; i < tempWidth; i++) {
        (*res)[check++] = ' ';
      }
      for (int i = 0; i < digitCount; i++) {
        (*res)[check++] = resTemp[i];
      }
    }
  } else {
    for (int i = 0; i < digitCount; i++) {
      (*res)[check++] = resTemp[i];
    }
  }
  return check;
}

int processingFlagsForF(Flags *flag, double num, char **final, int checkFinal) {
  int checkMinus = 0;
  if (num < 0) {
    checkMinus = 1;
    num *= -1.0;
  }
  char res[1024] = {0};
  char digitTemp[1024] = {0};
  char decimalTemp[1024] = {0};
  long long temp = (long long)num;
  int checkAccuracy = flag->accuracy;
  int digitCount = 0;
  int countDecimals = 0;
  double tempNum = num - (long long)num;

  if (temp == 0) {
    digitCount++;
  } else {
    while (temp >= 1.0) {
      digitCount++;
      temp /= 10;
    }
  }
  temp = (long long)num;
  for (int i = digitCount - 1; i >= 0; i--) {
    digitTemp[i] = (temp % 10) + '0';
    temp /= 10;
  }

  if (tempNum + 0.000000001 >= 1.0) {
    long long integerPart = atoll(digitTemp);
    integerPart++;
    long long tempInteger = integerPart;
    int countInteget = 0;
    while (tempInteger != 0) {
      countInteget++;
      tempInteger /= 10;
    }
    for (int i = countInteget - 1; i >= 0; i--) {
      digitTemp[i] = (integerPart % 10) + '0';
      integerPart /= 10;
    }
    tempNum = 0.0;
  }
  if (flag->accuracy == 0) {
    double nextDigit = tempNum * 10;
    if ((int)nextDigit >= 5) {
      long long lastDigit = atoll(digitTemp);
      lastDigit++;
      long long tempLastDigit = lastDigit;
      int countInteger = 0;
      while (tempLastDigit != 0) {
        countInteger++;
        tempLastDigit /= 10;
      }
      for (int i = countInteger - 1; i >= 0; i--) {
        digitTemp[i] = (lastDigit % 10) + '0';
        lastDigit /= 10;
      }
      digitCount = countInteger;
    }
  }

  while (flag->accuracy > 0) {
    tempNum *= 10;
    int digit = (int)tempNum;
    decimalTemp[countDecimals++] = digit + '0';
    tempNum -= digit;
    flag->accuracy--;

    if (flag->accuracy == 0) {
      double nextDigit = tempNum * 10;
      if ((int)nextDigit >= 5) {
        int lastIndex = countDecimals - 1;
        decimalTemp[lastIndex]++;

        while (lastIndex >= 0 && decimalTemp[lastIndex] > '9') {
          decimalTemp[lastIndex--] = '0';
          if (lastIndex >= 0) {
            decimalTemp[lastIndex]++;
          }
        }
        if (lastIndex < 0) {
          long long integerPart = atoll(digitTemp);
          integerPart++;
          long long tempInteger = integerPart;
          int countInteget = 0;
          while (tempInteger != 0) {
            countInteget++;
            tempInteger /= 10;
          }
          digitCount = 0;
          for (int i = countInteget - 1; i >= 0; i--) {
            digitTemp[i] = (integerPart % 10) + '0';
            integerPart /= 10;
            digitCount++;
          }
        }
      }
    }
  }

  int tempCheck = 0;
  if (flag->flagPlus == 1 && checkMinus == 0) {
    res[tempCheck++] = '+';

  } else if (checkMinus == 1) {
    res[tempCheck++] = '-';
  }
  if (flag->flagPlus == 0 && flag->flagSpace == 1 && checkMinus == 0) {
    res[tempCheck++] = ' ';
  }

  for (int i = 0; i < digitCount; i++) {
    res[tempCheck++] = digitTemp[i];
  }
  if (checkAccuracy != 0) {
    res[tempCheck++] = '.';

    for (int i = 0; i < countDecimals; i++) {
      res[tempCheck++] = decimalTemp[i];
    }
  }

  if (flag->flagMinus == 1 && flag->width > tempCheck) {
    for (int i = tempCheck; i < flag->width; i++) {
      res[tempCheck++] = ' ';
    }
  }
  if (flag->flagMinus == 0 && flag->width > tempCheck) {
    for (int i = flag->width - 1; i >= 0; i--) {
      res[i + (flag->width - tempCheck)] = res[i];
    }
    for (int i = 0; i < flag->width - tempCheck; i++) {
      res[i] = ' ';
    }
    tempCheck += flag->width - tempCheck;
  }
  res[tempCheck] = '\0';
  int i = 0;
  while (res[i] != '\0') {
    (*final)[checkFinal++] = res[i++];
  }

  (*final)[checkFinal] = '\0';
  return checkFinal;
}

int spec_s(char **res, char *s, int check, Flags *flag) {
  if (s != s21_NULL) {
    int len = 0;
    while (s[len] != '\0') {
      len++;
    }

    if (flag->accuracy >= 0 && flag->accuracy < len) {
      len = flag->accuracy;
    }

    int width = flag->width - len;

    if (flag->flagMinus == 0 && width > 0) {
      for (int i = 0; i < width; i++) {
        (*res)[check++] = ' ';
      }
    }

    for (int i = 0; i < len; i++) {
      (*res)[check++] = s[i];
    }

    if (flag->flagMinus == 1 && width > 0) {
      for (int i = 0; i < width; i++) {
        (*res)[check++] = ' ';
      }
    }

    (*res)[check] = '\0';
  } else {
    const char *null_str = "(null)";
    int null_len = 6;

    if (flag->accuracy >= 0 && flag->accuracy < null_len) {
      null_len = flag->accuracy;
    }

    int width = flag->width - null_len;

    if (flag->flagMinus == 0 && width > 0) {
      for (int i = 0; i < width; i++) {
        (*res)[check++] = ' ';
      }
    }

    for (int i = 0; i < null_len; i++) {
      (*res)[check++] = null_str[i];
    }

    if (flag->flagMinus == 1 && width > 0) {
      for (int i = 0; i < width; i++) {
        (*res)[check++] = ' ';
      }
    }

    (*res)[check] = '\0';
  }

  return check;
}

void s21_errors_sprintf(char **str, Flags *flag, const char *format,
                        s21_size_t *check) {
  (*str)[(*check)++] = '%';

  if (flag->flagMinus == 1) {
    (*str)[(*check)++] = '-';
  }

  if (flag->flagPlus == 1) {
    (*str)[(*check)++] = '+';
  }

  if (flag->flagSpace == 1) {
    (*str)[(*check)++] = ' ';
  }

  if (flag->width > 0) {
    char tempWidt[1024] = {0};
    int widthLength = s21_sprintf(tempWidt, "%d", flag->width);
    for (int i = 0; i < widthLength; i++) {
      (*str)[(*check)++] = tempWidt[i];
    }
  }
  if (flag->accuracy >= 0) {
    (*str)[(*check)++] = '.';
    char tempAccuracy[1024] = {0};
    int accuracyLength = s21_sprintf(tempAccuracy, "%d", flag->accuracy);
    for (int i = 0; i < accuracyLength; i++) {
      (*str)[(*check)++] = tempAccuracy[i];
    }
  }

  if (flag->length == 'l' || flag->length == 'h') {
    (*str)[(*check)++] = flag->length;
  }
  (*str)[(*check)++] = *format;
}
