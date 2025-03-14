#include <stdio.h>

char board[3][3];  // لوحة اللعب
char player = 'X';  // اللاعب الأول يبدأ بـ X
int row, col;  // لتحديد الصف والعمود الذي سيتم اللعب فيه

// دالة لتهيئة اللوحة
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// دالة لعرض اللوحة
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// دالة للتحقق من الفائز
int checkWin() {
    // التحقق من الصفوف
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    // التحقق من الأعمدة
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1;
        }
    }

    // التحقق من القطر الأول
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    // التحقق من القطر الثاني
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }

    return 0;  // لا يوجد فائز بعد
}

// دالة للتحقق من أن اللعبة انتهت بالتعادل
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;  // إذا كان هناك مكان فارغ، فلا يوجد تعادل بعد
            }
        }
    }
    return 1;  // إذا كانت كل الخلايا ممتلئة والتعادل
}

// دالة لتنفيذ حركة اللاعب
void playerMove() {
    printf("اللاعب %c، اختر الصف (0-2) والعمود (0-2): ", player);
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
    } else {
        printf("موقع غير صالح! حاول مرة أخرى.\n");
        playerMove();
    }
}

// دالة لتبديل اللاعبين
void switchPlayer() {
    if (player == 'X') {
        player = 'O';
    } else {
        player = 'X';
    }
}

int main() {
    int gameStatus = 0;  // حالة اللعبة: 0 = اللعبة مستمرة، 1 = فوز، 2 = تعادل
    initializeBoard();  // تهيئة اللوحة

    while (gameStatus == 0) {
        printBoard();  // عرض اللوحة
        playerMove();  // إجراء حركة اللاعب
        gameStatus = checkWin();  // التحقق من الفوز
        if (gameStatus == 0) {
            gameStatus = checkDraw();  // التحقق من التعادل
        }

        if (gameStatus == 0) {
            switchPlayer();  // تبديل اللاعبين
        }
    }

    printBoard();  // عرض اللوحة الأخيرة

    if (gameStatus == 1) {
        printf("اللاعب %c فاز!\n", player);  // إعلان الفائز
    } else {
        printf("اللعبة انتهت بالتعادل!\n");  // إذا كان التعادل
    }

    return 0;
}
