#include "s21_string_test.h"

START_TEST(test_strtok_1) {
  char string1[] = "apple,banana,cherry";
  char string2[] = "apple,banana,cherry";
  char string3[] = ",";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_2) {
  char string1[] = "red|green|blue";
  char string2[] = "red|green|blue";
  char string3[] = "|";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_3) {
  char string1[] = "one::two::three";
  char string2[] = "one::two::three";
  char string3[] = "::";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_4) {
  char string1[] = "alpha beta gamma";
  char string2[] = "alpha beta gamma";
  char string3[] = " ";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_5) {
  char string1[] = "1+2=3";
  char string2[] = "1+2=3";
  char string3[] = "=";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_6) {
  char string1[] = "1+2=3";
  char string2[] = "1+2=3";
  char string3[] = "+2";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_7) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  char string3[] = "4";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_8) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  char string3[] = "12";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_9) {
  char string1[] = "1234567890";
  char string2[] = "1234567890";
  char string3[] = "";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_10) {
  char string1[] = "\0";
  char string2[] = "\0";
  char string3[] = "11";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_11) {
  char string1[] = "1+2=3";
  char string2[] = "1+2=3";
  char string3[] = "3=";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_12) {
  char string1[] = "Hello,-! world!";
  char string2[] = "Hello,-! world!";
  char string3[] = "!-";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_13) {
  char string1[] = "";
  char string2[] = "";
  char string3[] = "";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_14) {
  char string1[] = "";
  char string2[] = "";
  char string3[] = "1";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_15) {
  char string1[] = "123";
  char string2[] = "123";
  char string3[] = "";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_16) {
  char string1[] = "apple,banana,cherry";
  char string2[] = "apple,banana,cherry";
  char string3[] = "apple,banana,cherry";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_17) {
  char string1[] = "apple,banana,cherry";
  char string2[] = "apple,banana,cherry";
  char string3[] = "y";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_18) {
  char string1[] = "apple,banana,cherry";
  char string2[] = "apple,banana,cherry";
  char string3[] = "B";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_19) {
  char string1[] = "\napple,banana,cherry";
  char string2[] = "\napple,banana,cherry";
  char string3[] = "a";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_20) {
  char string1[] = "\0apple,banana,cherry";
  char string2[] = "\0apple,banana,cherry";
  char string3[] = "\0";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_21) {
  char string1[] = "\0apple,banana,cherry";
  char string2[] = "\0apple,banana,cherry";
  char string3[] = "";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

START_TEST(test_strtok_22) {
  char string1[] = "hrom brom maf";
  char string2[] = "hrom brom maf";
  char string3[] = "hrom bro";
  char *string4 = strtok(string1, string3);
  char *string6 = strtok(s21_NULL, string3);

  char *string5 = s21_strtok(string2, string3);
  char *string7 = s21_strtok(s21_NULL, string3);

  ck_assert_pstr_eq(string1, string2);
  ck_assert_pstr_eq(string4, string5);
  ck_assert_pstr_eq(string6, string7);
}
END_TEST

START_TEST(test_strtok_23) {
  char string1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char string2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char string3[] = "Come here";
  char string4[] = "Come here";
  char string5[] = "l";
  char string6[] = " ";

  ck_assert_str_eq(strtok(string1, string5), s21_strtok(string2, string5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, string6), s21_strtok(s21_NULL, string6));
  }
  ck_assert_pstr_eq(strtok(string3, string6), s21_strtok(string4, string6));
  ck_assert_pstr_eq(strtok(s21_NULL, string6), s21_strtok(s21_NULL, string6));
  ck_assert_pstr_eq(strtok(s21_NULL, string6), s21_strtok(s21_NULL, string6));
}
END_TEST

START_TEST(test_strtok_24) {
  char string1[] = "apple,banana,cherry";
  char string2[] = "apple,banana,cherry";
  char string3[] = ",";
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
  ck_assert_pstr_eq(s21_strtok(string1, string3), strtok(string2, string3));
}
END_TEST

Suite *test_strtok(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("s21_strtok");
  core = tcase_create("Core");

  tcase_add_test(core, test_strtok_1);
  tcase_add_test(core, test_strtok_2);
  tcase_add_test(core, test_strtok_3);
  tcase_add_test(core, test_strtok_4);
  tcase_add_test(core, test_strtok_5);
  tcase_add_test(core, test_strtok_6);
  tcase_add_test(core, test_strtok_7);
  tcase_add_test(core, test_strtok_8);
  tcase_add_test(core, test_strtok_9);
  tcase_add_test(core, test_strtok_10);
  tcase_add_test(core, test_strtok_11);
  tcase_add_test(core, test_strtok_12);
  tcase_add_test(core, test_strtok_13);
  tcase_add_test(core, test_strtok_14);
  tcase_add_test(core, test_strtok_15);
  tcase_add_test(core, test_strtok_16);
  tcase_add_test(core, test_strtok_17);
  tcase_add_test(core, test_strtok_18);
  tcase_add_test(core, test_strtok_19);
  tcase_add_test(core, test_strtok_20);
  tcase_add_test(core, test_strtok_21);
  tcase_add_test(core, test_strtok_22);
  tcase_add_test(core, test_strtok_23);
  tcase_add_test(core, test_strtok_24);

  suite_add_tcase(suite, core);

  return (suite);
}
