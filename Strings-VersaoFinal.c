#include <stdio.h>
#include <string.h>
//Git comment like a champ
int main(void)
{
	char nome[1000];
	int conta_letras[26]; // 26 letras do alfabeto
	int i, j, max, conta_palavras = 0;

	printf("Insira Nome:\n");
	gets(nome);
	
	// Converte todos os caracteres da string para maiúsculas
	strupr(nome);
	
	// Ignora caracteres de espaço, no início da string
	for (i = 0; nome[i] == ' '; i++);

	// Se existe pelo menos um carácter
	if (nome[i] != '\0')
	{
		// Então há pelo menos uma palavra
		conta_palavras = 1;
	}

	// Conta palavras
	for (j = i; nome[j] != '\0'; j++)
	{
		if (nome[j] == ' ')
		{
			conta_palavras++;

			// Ignora uma sequência de espaços
			while (nome[j + 1] == ' ')
			{
				j++;
			}
		}
	}

	// Se o último carácter é um espaço, e há pelo menos uma palavra
	if ((nome[j - 1] == ' ') && (conta_palavras >= 1))
	{
		// Então há menos uma palavra
		conta_palavras--;
	}

	printf("\nNumero de palavras: %d\n", conta_palavras);

	// Conta letras
	for (i = 0; i<(int)strlen(nome); i++)
	{
		if ((nome[i] >= 'A') && (nome[i] <= 'Z'))
		{
			conta_letras[nome[i] - 65]++; // Nota que 'A' tem valor decimal 65
		}
	}

	// Encontra o maior número de ocorrências
	max = conta_letras[0];


	for (i = 1; i<26; i++)
	{
		if (max < conta_letras[i])
		{
			max = conta_letras[i];
		}
	}

	// Encontra a(s) letra(s) mais frequente(s)
	for (i = 0; i<26; i++)
	{
		if (conta_letras[i] == max)
		{
			printf("\nLETRA: %c", i + 65); // Nota que o valor decimal 65 corresponde ao carácter 'A'
		}
	}

	return 0;
}