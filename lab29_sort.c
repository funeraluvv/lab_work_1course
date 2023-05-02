//Задача 29B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //объявление структуры
    char departure[100];
    char time[6];
    int number;
} train;

//t - указатель на массив структур train

//функция заполнения структур
void input_train(train *t, int n) {
    	for (int i = 0; i < n; i++) {
        printf("Departure city: ");
        scanf("%s", t[i].departure);
        printf("Departure time (HH:MM): ");
        scanf("%s", t[i].time);
        printf("Train number: ");
        scanf("%d", &t[i].number);
    }
}

// функция для записи массива структур в файл
void write_trains_to_file(train *t, int n, char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s %s %d\n", t[i].departure, t[i].time, t[i].number);
    }
    fclose(f);
}

// функция для чтения массива структур из файла
void read_trains_from_file(train *t, int n, char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s %s %d\n", t[i].departure, t[i].time, &t[i].number);
    }
    fclose(f);
}

// функция для вывода массива структур на экран
void print_trains(train *t, int n) {
    printf("__________________\n");
    printf("Trains:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", t[i].departure, t[i].time, t[i].number);
    }
      printf("__________________\n");
}

void selection_sort(train *trains, int n) { //функция для сортировки массива структур методом выбора по полю номера
    int i, j, min_idx;
    train temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (trains[j].number < trains[min_idx].number) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = trains[i];
            trains[i] = trains[min_idx];
            trains[min_idx] = temp;
        }
    }
}



void shell_sort(train *trains, int n) { // сортирвока методом Шелла по полю номера
    int i, j, gap;
    train temp;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = trains[i];
            for (j = i; j >= gap && temp.number < trains[j - gap].number; j -= gap) {
                trains[j] = trains[j - gap];
            }
            trains[j] = temp;
        }
    }
}


int main() {
    int n = 3;
    train *t = malloc(n * sizeof(train)); // выделение памяти под массив структур
    if (t == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    printf("Enter information about %d trains:\n", n);
    input_train(t, n);

    write_trains_to_file(t, n, "trains.txt");
    read_trains_from_file(t, n, "trains.txt");
    print_trains(t, n);

    printf("Choose sorting method (1 for selection sort, 2 for shell sort): "); // выбор метода сортировки
    int mode;
    scanf("%d", &mode);

    switch (mode) {
        case 1:
            selection_sort(t, n);
            write_trains_to_file(t, n, "sorted_trains_1.txt");
            read_trains_from_file(t, n, "sorted_trains_1.txt");
            print_trains(t, n);
            break;
        case 2:
            shell_sort(t, n);
            write_trains_to_file(t, n, "sorted_trains_2.txt");
            read_trains_from_file(t, n, "sorted_trains_2.txt");
            print_trains(t, n);
            break;
        default:
            printf("Not selected.\n");
            break;
    }

    free(t); // освобождение выделенной памяти
    return 0;
}
