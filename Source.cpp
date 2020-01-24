#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ptb");

	string nomeCliente;
	float precoMercadoria = 0, totalMercadoria = 0, ICMS, IPI, PIS, COFINS, totalImposto = 0, totalGeral = 0, totalAtual = 0, totalImpostoAtual = 0, imposto, desconto;
	int qntdComprada;
	char resposta;
	resposta = 'S';

	while (toupper(resposta) == 'S')
	{
		
		cout << "Informe o nome do cliente: " << endl;
		getline(cin, nomeCliente);
		

		cout << "Informe o número de produtos comprados: " << endl;
		cin >> qntdComprada;

		precoMercadoria = qntdComprada * 4.50;

		totalMercadoria += precoMercadoria;

		cout << "Cliente: " << nomeCliente << endl;

		ICMS = precoMercadoria / 100 * 18;
		IPI = precoMercadoria / 100 * 4;
		PIS = precoMercadoria / 100 * 1.86;
		COFINS = precoMercadoria / 100 * 8.54;

		imposto = ICMS + IPI + PIS + COFINS;
		totalImposto += imposto;
		totalImpostoAtual = imposto;

		totalAtual = precoMercadoria + totalImpostoAtual;
		
		if (qntdComprada >= 1000)
		{
			totalAtual = totalAtual - (precoMercadoria + totalImpostoAtual) / 100 * 5;
			cout << "ICMS: " << ICMS << ";" << " IPI: " << IPI << ";" << " PIS: " << PIS << ";" << " COFINS: " << COFINS << ";" << "  Total (com 5% de desconto): " << totalAtual << ";" << endl;
			totalGeral += totalAtual;
		}
		
		else
		{
			totalAtual = precoMercadoria + totalImpostoAtual;
			cout << "ICMS: " << ICMS << ";" << " IPI: " << IPI << ";" << " PIS: " << PIS << ";" << " COFINS: " << COFINS << ";" << "  Total: " << totalAtual << ";" << endl;
			totalGeral += totalAtual;
		}

		cout << "Deseja cadastrar um novo cliente? (Responda com 'S' ou 'N')" << endl;
		cin >> resposta;
		cin.ignore();

		while (toupper(resposta) != 'S' && toupper(resposta) != 'N')
		{
			cout << "Erro, digite um caracter valido ('S' para cadastrar um novo cliente ou 'N' para finalizar o processo)" << endl;
			cin >> resposta;	
			cin.ignore();
		}
			
	}

	
	cout << "Total dos impostos: " << totalImposto << endl;
	
	cout << "O valor total é: " << totalGeral << endl;

	cout << "O valor da mercadoria é: " << totalMercadoria << endl;

		
	system("pause");
	return 0;
}

//abstração
//nome cliente = string
//qntd q comprou = int
//preço mercadoria = float
//impostos 1 / 2 / 3 / 4 = float
//total impostos = float
//total geral = float

//● ICMS : 18 %
//● IPI : 4 %
//● PIS : 1, 86 %
//● COFINS : 8, 54 %