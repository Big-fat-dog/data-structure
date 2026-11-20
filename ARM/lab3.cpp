struct User {
    int id;
    int age;
    int score;
};

int test(User* user, int* arr, int index) {
    int a = user->score;
    int b = arr[index];
    return a + b;
}