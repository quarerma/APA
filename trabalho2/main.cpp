#include "include/Graph.hpp"
#include "include/defines.hpp"

int main (int argc, char *argv[]) {
    if (argc < 2) { 
        std::cerr << "Erro: Faltando o nome do arquivo de entrada." << std::endl;
        std::cerr << "Uso: " << argv[0] << " <caminho_para_o_arquivo>" << std::endl;
        return 1; 
    }
    std::string nome_arquivo = argv[1];
    std::ifstream instance_file(nome_arquivo);
    //verifica se o arquivo foi aberto corretamente
    if (!instance_file.is_open()) {
        std::cerr << "Nao foi possivel abrir o arquivo " << nome_arquivo << std::endl;
        return 1;
    }
    Graph graph(instance_file, true, false, false);
    //verifica se o grafo orientado é fracamente conexo
    bool eh_conexo = graph.verifica_conectividade_fraca();
    if (eh_conexo) {
        std::cout << "O grafo orientando eh conexo." << std::endl;
    } else {
        std::cout << "O grafo orientado eh desconexo." << std::endl;
    }
    return 0;
}
