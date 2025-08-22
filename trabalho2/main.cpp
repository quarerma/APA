#include "include/Graph.hpp"
#include "include/defines.hpp"
#include <chrono>

int main (int argc, char *argv[]) {
    if (argc < 3) { 
        std::cerr << "Erro: Faltando parâmetros." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <caminho_para_o_arquivo> <direcionado?>" << std::endl;
        return 1; 
    }
    std::string nome_arquivo = argv[1];
    std::string direcionado = argv[2];

    std::ifstream instance_file(nome_arquivo);
    if(direcionado != "true" && direcionado != "false") {
        std::cerr << "Erro: O segundo parâmetro deve ser 'true' ou 'false'." << std::endl;
        return 1;
    }

    //verifica se o arquivo foi aberto corretamente
    if (!instance_file.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo " << nome_arquivo << std::endl;
        return 1;
    }

    Graph graph(instance_file, direcionado == "true");
    auto start = std::chrono::high_resolution_clock::now();
    //verifica se o grafo orientado é fracamente conexo
    bool eh_conexo = graph.verifica_conectividade_fraca();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    if (eh_conexo) {
        std::cout << "O grafo " << ((direcionado == "true") ? "" : "não ") << "orientado eh conexo." << std::endl;
    } else {
        std::cout << "O grafo " << ((direcionado == "true") ? "" : "não ") << "orientado eh desconexo." << std::endl;
    }
    std::cout << "Tempo de execucao: " << elapsed.count() << " nanosegundos." << std::endl;
    return 0;
}
