#include <stdio.h>
#include <stdlib.h>

typedef struct dynArray DynArray;
struct dynArray{
	int* array; // Here, we implement a dynamic array of int
	size_t used; // The number of used entries
	size_t size; // The memory allocated to the array is stored here
};

DynArray* initialize_arr(size_t initialSize){
    DynArray* a = (DynArray*)malloc(sizeof(DynArray));
    a->array = (int*)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
    return a;
}
void insert_arr(DynArray* a, int element){
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int*)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}
void display_arr(DynArray* a) {
    for (size_t i = 0; i < a->used; i++) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}
void free_arr(DynArray* a){
    free(a->array);
    free(a);
}
int main() {
    DynArray* a = initialize_arr(2);
    insert_arr(a, 10);
    insert_arr(a, 20);
    insert_arr(a, 30);
    display_arr(a);
    free_arr(a);
    return 0;
}