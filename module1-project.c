#include <stdio.h>
struct User 
{
    int userID;
    int balance;
};
const char* perform_transaction(struct User users[], int N, int from_userID, int to_userID, int amount) {
    int from_index = -1, to_index = -1;
    for (int i = 0; i < N; i++) {
        if (users[i].userID == from_userID) {
            from_index = i;
        }
        if (users[i].userID == to_userID) {
            to_index = i;
        }
    }
    if (from_index != -1 && to_index != -1 && users[from_index].balance >= amount) {
        users[from_index].balance -= amount;
        users[to_index].balance += amount;
        return "Success";
    } else {
        return "Failure";
    }
}
void sort_users(struct User users[], int N) {
    struct User temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (users[i].balance > users[j].balance || 
                (users[i].balance == users[j].balance && users[i].userID > users[j].userID)) {
                temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }
}
int main() {
    int N, T;
    scanf("%d", &N);
    struct User users[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &users[i].userID, &users[i].balance);
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int from_userID, to_userID, amount;
        scanf("%d %d %d", &from_userID, &to_userID, &amount);
        const char* result = perform_transaction(users, N, from_userID, to_userID, amount);
        printf("%s\n", result);
    }
    sort_users(users, N);
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", users[i].userID, users[i].balance);
    }
    return 0;
}
