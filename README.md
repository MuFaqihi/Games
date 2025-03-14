. Variables :
تم استخدام المتغيرات في البرنامج لتخزين البيانات المختلفة مثل:

char board[3][3]: لتخزين حالة اللوحة.
int turn: لتحديد أي لاعب دوره.
int choice: لحفظ الرقم الذي يختاره اللاعب (من 1 إلى 9).
bool winner_found: لتحديد ما إذا تم العثور على فائز أم لا.
2. if, else (الشروط):
تم استخدام الشروط في عدة أماكن في البرنامج:

في دالة check_winner: للتحقق مما إذا كانت هناك ثلاث خلايا متشابهة في صف، عمود، أو قطر. يتم استخدام if للتحقق من كل حالة على حدة.
في دالة is_full: للتحقق إذا كانت اللوحة ممتلئة أم لا.
في دالة main: للتحقق من صحة المدخلات (تأكد من أن الرقم بين 1 و 9).
مثال:

if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
    return true;
3. while:
يتم استخدام حلقة while في دالة main لمتابعة اللعبة حتى يتم العثور على فائز أو تصل اللعبة إلى تعادل:

while (!winner_found && !is_full(board)) {
  اللعبة تستمر حتى يتم العثور على فائز أو تمتلئ اللوحة
}
4. Functions :
يوجد العديد من الدوال التي تم استخدامها لتنظيم الكود:

display_logo(): لعرض الشعار.
display_board(): لعرض اللوحة.
check_winner(): للتحقق من فوز أحد اللاعبين.
is_full(): للتحقق إذا كانت اللوحة ممتلئة.
print_winner_symbol(): لعرض شكل كبير عند فوز اللاعب.
5. Nested loops (الحلقات المتداخلة):
تم استخدام حلقات متداخلة في دالة display_board لطباعة محتويات اللوحة:

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf(" %c ", board[i][j]);
        if (j < 2) printf("|");
    }
    printf("\n");
    if (i < 2) printf("---+---+---\n");
}
6. Pointers, arrays, and strings:
arrays: تم استخدام المصفوفات في عدة أماكن:
-char board[3][3], مصفوفة 2D لتمثيل اللوحة.
-char name[50], مصفوفة من الأحرف لتخزين اسم اللاعب.
strings: استخدام السلاسل النصية لتخزين أسماء اللاعبين باستخدام strncpy أو snprintf في دالة main.
Pointers: استخدام المؤشرات عند التعامل مع السلاسل النصية، مثل:

snprintf(players[0].name, 50, "%s", argv[1]);
7. argc, argv (عدد المعاملات والمدخلات من سطر الأوامر):
استخدام argc و argv في البرنامج لاستقبال أسماء اللاعبين من سطر الأوامر:

argc: عدد المعاملات المدخلة من سطر الأوامر.
argv: مصفوفة تحتوي على المعاملات المدخلة (مثل أسماء اللاعبين).

if (argc > 2) {
    snprintf(players[0].name, 50, "%s", argv[1]);
    snprintf(players[1].name, 50, "%s", argv[2]);
} else {
    snprintf(players[0].name, 50, "Player 1");
    snprintf(players[1].name, 50, "Player 2");
}
8. Structures, typedef:
استخدام (struct) في البرنامج لتخزين معلومات اللاعب:

Player: هيكل يحتوي على name (اسم اللاعب) و symbol (رمز اللاعب مثل 'X' أو 'O').
وفيما يتعلق بـ typedef، تم تعريف النوع Player ليصبح نوعًا مخصصًا يمكن استخدامه في البرنامج:


typedef struct {
    char name[50];
    char symbol;
} Player;
