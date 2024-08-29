#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 25 * 1024 // 25KB memori (25,600B)
#define DIVIDER 128

char memory[MAX_MEMORY];
int memory_used = 0;

typedef struct
{
    void *address;
    size_t size;
    size_t actualSize;
} MemoryBlock;

MemoryBlock memory_blocks[MAX_MEMORY / DIVIDER];
int block_count = 0;

void *first_fit_malloc(size_t size);
void *best_fit_malloc(size_t size);
void *worst_fit_malloc(size_t size);
void my_free(void *ptr);
void monitor_memory_usage();

void *first_fit_malloc(size_t size)
{
    // Cari blok memori yang cukup
    for (int i = 0; i < block_count; i++)
    {
        if (memory_blocks[i].size >= size && memory_blocks[i].address == NULL)
        {
            memory_blocks[i].address = memory + i * DIVIDER;
            memory_blocks[i].actualSize = size;
            memory_used += size;
            return memory_blocks[i].address;
        }
    }

    // Jika tidak ada blok memori yang cukup, alokasikan blok baru
    if (block_count * DIVIDER + size + memory_used <= MAX_MEMORY)
    {
        memory_blocks[block_count].address = memory + block_count * DIVIDER;
        memory_blocks[block_count].size = size;
        memory_blocks[block_count].actualSize = size;
        block_count++;
        memory_used += size;
        return memory_blocks[block_count - 1].address;
    }
    return NULL;
}

void *best_fit_malloc(size_t size)
{
    int best_idx = -1;
    size_t best_size = MAX_MEMORY + 1;
    // Cari blok memori yang cukup dan paling kecil
    for (int i = 0; i < block_count; i++)
    {
        if (memory_blocks[i].size >= size && memory_blocks[i].address == NULL && memory_blocks[i].size < best_size)
        {
            best_idx = i;
            best_size = memory_blocks[i].size;
        }
    }
    if (best_idx != -1)
    {
        memory_blocks[best_idx].address = memory + best_idx * DIVIDER;
        memory_blocks[best_idx].actualSize = size;
        memory_used += size;
        return memory_blocks[best_idx].address;
    }
    // Jika tidak ada blok memori yang cukup, alokasikan blok baru
    if (block_count * DIVIDER + size + memory_used <= MAX_MEMORY)
    {
        memory_blocks[block_count].address = memory + block_count * DIVIDER;
        memory_blocks[block_count].size = size;
        memory_blocks[block_count].actualSize = size;
        block_count++;
        memory_used += size;
        return memory_blocks[block_count - 1].address;
    }
    return NULL;
}

void *worst_fit_malloc(size_t size)
{
    int worst_idx = -1;
    size_t worst_size = 0;
    // Cari blok memori yang cukup dan paling besar
    for (int i = 0; i < block_count; i++)
    {
        if (memory_blocks[i].size >= size && memory_blocks[i].address == NULL && memory_blocks[i].size > worst_size)
        {
            worst_idx = i;
            worst_size = memory_blocks[i].size;
        }
    }
    if (worst_idx != -1)
    {
        memory_blocks[worst_idx].address = memory + worst_idx * DIVIDER;
        memory_blocks[worst_idx].actualSize = size;
        memory_used += size;
        return memory_blocks[worst_idx].address;
    }
    // Jika tidak ada blok memori yang cukup, alokasikan blok baru
    if (block_count * DIVIDER + size + memory_used <= MAX_MEMORY)
    {
        memory_blocks[block_count].address = memory + block_count * DIVIDER;
        memory_blocks[block_count].size = size;
        memory_blocks[block_count].actualSize = size;
        block_count++;
        memory_used += size;
        return memory_blocks[block_count - 1].address;
    }
    return NULL;
}

void my_free(void *ptr)
{
    for (int i = 0; i < block_count; i++)
    {
        if (memory_blocks[i].address == ptr)
        {
            memory_blocks[i].address = NULL;
            memory_used -= memory_blocks[i].size;
            break;
        }
    }
}

void print_memory_status()
{
    printf("Memory Status:\n");
    for (int i = 0; i < block_count; i++)
    {
        (memory_blocks[i].address != NULL) ? printf("Block %d: Address = %p, Size = %zu, Used = %s, Actual Size: %zu\n",
                                                    i + 1, memory_blocks[i].address, memory_blocks[i].size,
                                                    (memory_blocks[i].address != NULL) ? "Yes" : "No", memory_blocks[i].actualSize)
                                           : printf("Block %d: Address = %p, Size = %zu, Used = %s\n",
                                                    i + 1, memory_blocks[i].address, memory_blocks[i].size,
                                                    (memory_blocks[i].address != NULL) ? "Yes" : "No");
    }
}

void monitor_memory_usage()
{
    printf("Memory used: %d bytes\n\n", memory_used);
}

void task1(void *(*alloc_func)(size_t), const char *alg_name)
{
    printf("Starting task with %s allocation...\n", alg_name);
    size_t size;
    int error = 0;
    // Phase 1: Membuat blok memori dengan ukuran bervariasi dan mendealokasi memori
    printf("Phase 1\n");
    for (int i = 0; i < 10; i++)
    {                             // Perform n allocations, this number can be changed
        size = rand() % 4096 + 1; // Allocate between 1 and 4096 bytes
        void *ptr = alloc_func(size);
        if (ptr == NULL)
        {
            error = 1;
            printf("Failed to allocate memory at iteration %d \n", i + 1);
            break;
        }
    }

    // Perform dealocations in a random order
    for (int i = 0; i < block_count; i += 2)
    {
        my_free(memory_blocks[i].address);
    }
    print_memory_status();
    if (error)
    {
        printf("Next allocation size: %d\n", size);
    }
    printf("Remaining memory: %d\n", MAX_MEMORY - memory_used);
    monitor_memory_usage();

    // Phase 2: Mengalokasikan memori ke blok memori yang kosong
    printf("Phase 2\n");
    for (int i = 0; i < 10; i++)
    {                             // Perform n allocations, this number can be changed
        size = rand() % 4096 + 1; // Allocate between 1 and 4096 bytes
        printf("%d. Allocating %d bytes\n", i + 1, size);
        void *ptr = alloc_func(size);
        if (ptr == NULL)
        {
            error = 1;
            printf("Failed to allocate memory at iteration %d \n", i + 1);
            break;
        }
        print_memory_status();
    }

    if (error)
    {
        printf("Next allocation size: %d\n", size);
    }
    printf("Remaining memory: %d\n", MAX_MEMORY - memory_used);
    monitor_memory_usage();
}

int main()
{
    task1(first_fit_malloc, "First Fit");
    // Reinitialize variables
    memory_used = 0;
    block_count = 0;
    memset(memory_blocks, 0, sizeof(memory_blocks));
    task1(best_fit_malloc, "Best Fit");
    // Reinitialize variables
    memory_used = 0;
    block_count = 0;
    memset(memory_blocks, 0, sizeof(memory_blocks));
    task1(worst_fit_malloc, "Worst Fit");

    system("pause");
    return 0;
}