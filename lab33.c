#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//Вариант 6.

/*Составить процедуру, определяющую вхождение списка L1 в список L2 и наоборот.
Если один из списков длиннее, удалить лишние элементы из его начала.
Используя процедуру, проанализировать пары списков M1 и M2, N1 и N2.*/

/* Описание структуры односвязного списка */
typedef struct node {
    int data;           // данные узла
    struct node* next;  // указатель на следующий узел
} Node;

/* Функция для создания нового узла */
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

/* Функция для добавления узла в конец списка */
void append(Node** head, int data) {
    Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

/* Функция для удаления первых n узлов из списка */
void deleteN(Node** head, int n) {
    for (int i = 0; i < n; i++) {
        if (*head != NULL) {
            Node* current = *head;
            *head = (*head)->next;
            free(current);
        }
    }
}

/* Функция для определения, входит ли список L1 в список L2 */
int isSubset(Node* L1, Node* L2) {
    Node* current1 = L1;
    Node* current2 = L2;

    while (current1 != NULL) {
        if (current2 == NULL) {
            return 0; // не входит
        }
        if (current1->data == current2->data) {
            current1 = current1->next;
        }
        current2 = current2->next;
    }

    return 1; //входит
}

/* Функция, обратная прошлой */
int ReSubSet(Node* L1, Node* L2) {
    return isSubset(L2, L1);
}

int main() {
    // Создание списков M1, M2, N1, N2
    Node* M1 = NULL;
    Node* M2 = NULL;
    Node* N1 = NULL;
    Node* N2 = NULL;

    int n1len, n2len, m1len, m2len, data;

    // Ввод элементов списка M1
    printf("Введите количество элементов в списке M1: ");
    scanf("%d", &m1len);
    printf("Введите элементы M1 через Enter: ");
    for (int i = 0; i < m1len; i++) {
        scanf("%d", &data);
        append(&M1, data);
    }

    // Ввод элементов списка M2
    printf("Введите количество элементов в списке M2: ");
    scanf("%d", &m2len);
    printf("Введите элементы M2 через Enter: ");
    for (int i = 0; i < m2len; i++) {
        scanf("%d", &data);
        append(&M2, data);
    }

    // Ввод элементов списка N1
    printf("Введите количество элементов в списке N1: ");
    scanf("%d", &n1len);
    printf("Введите элементы N1 через Enter: ");
    for (int i = 0; i < n1len; i++) {
        scanf("%d", &data);
        append(&N1, data);
    }

    // Ввод элементов списка N2
    printf("Введите количество элементов в списке N2: ");
    scanf("%d", &n2len);
    printf("Введите элементы N2 через Enter: ");
    for (int i = 0; i < n2len; i++) {
        scanf("%d", &data);
        append(&N2, data);
    }

    // Удаление лишних элементов из списков, если один из них длиннее
    int diff;
    if (m1len > m2len) {
        diff = m1len - m2len;
        deleteN(&M1, diff);
    } else {
        diff = m2len > m1len;
        deleteN(&M2, diff);
    }
    if (n1len > n2len) {
        diff = n1len - n2len;
        deleteN(&N1, diff);
    } else {
        diff = n2len > n1len;
        deleteN(&N2, diff);
    }

    // Определение, входит ли M1 в M2 и наоборот
    if (isSubset(M1, M2)) {
        printf("M1 - подсписок M2\n");
    } else {
        printf("M1 не входит в  M2\n");
    }
    if (ReSubSet(M1, M2)) {
        printf("M1 - подсписок M2\n");
    } else {
        printf("M1 не входит в M2\n");
    }

    // Определение, входит ли N1 в N2 и наоборот
    if (isSubset(N1, N2) == 1) {
        printf("N1 - подсписок N2\n");
    } else {
        printf("N1 не входит of N2\n");
    }
    if (ReSubSet(N1, N2) == 1) {
        printf("N1 - подсписок N2\n");
    } else {
        printf("N1 не входит в N2\n");
    }

    return 0;
    }
