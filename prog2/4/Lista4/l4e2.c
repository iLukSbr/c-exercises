#include <stdio.h>

int main()
{
    int dian, mesn, anon, diah, mesh, anoh, anos;
    printf("DD/MM/AAAA\n");
    printf("Data de hoje?\n");
    scanf("%d/%d/%d", &diah, &mesh, &anoh);
    printf("Data do seu nascimento?\n");
    scanf("%d/%d/%d", &dian, &mesn, &anon);
    if(mesh < mesn || mesh == mesn && diah < dian)
        anos = anoh - anon - 1;
    else
        anos = anoh - anon;
    printf("Idade = %d anos", anos);
    return 0;
}
