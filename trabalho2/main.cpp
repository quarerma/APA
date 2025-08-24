#include "include/Graph.hpp"
#include "include/defines.hpp"

void directed_test(std::ifstream &instance_file) {
    // std::cout << "================Teste com grafo direcionado================" << std::endl;
    bool direcionado = true;
    Graph directed_graph(instance_file, direcionado);

    // Tempo de execucao da funcao eh_conexo
    auto start = std::chrono::high_resolution_clock::now();
    bool eh_conexo = directed_graph.eh_conexo();
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    if (eh_conexo) {
        std::cout << "O grafo eh fortemente conexo." << std::endl;
    }
    else {
        std::cout << "O grafo nao eh fortemente conexo." << std::endl;
    }
    std::cout << "Tempo de execucao: " << elapsed.count() << " nanosegundos." << std::endl;
}

void undirected_test(std::ifstream &instance_file) {
    // std::cout << "==============Teste com grafo não direcionado==============" << std::endl;
    Graph undirected_graph(instance_file);

    // Tempo de execucao da funcao eh_conexo
    auto start = std::chrono::high_resolution_clock::now();
    bool eh_conexo = undirected_graph.eh_conexo();
    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    if (eh_conexo) {
        std::cout << "O grafo eh fracamente conexo." << std::endl;
    }
    else {
        std::cout << "O grafo nao eh conexo." << std::endl;
    }
    std::cout << "Tempo de execucao: " << elapsed.count() << " nanosegundos." << std::endl;
}

int main (int argc, char *argv[]) {
    // if (argc < 2) { 
    //     std::cerr << "Erro: Faltando nome do arquivo de entrada" << std::endl;
    //     std::cerr << "Uso: " << argv[0] << " <caminho_para_o_arquivo>" << std::endl;
    //     return 1; 
    // }
    // std::string nome_arquivo = argv[1];

    // std::ifstream instance_file(nome_arquivo);

    //verifica se o arquivo foi aberto corretamente
    // if (!instance_file.is_open()) {
    //     std::cerr << "Nao foi possivel abrir o arquivo " << nome_arquivo << std::endl;
    //     return 1;
    // }

    // // Teste com grafo direcionado
    // bool direcionado = true;
    // Graph directed_graph(instance_file, direcionado);

    // // Teste com grafo nao direcionado
    // Graph undirected_graph(instance_file);

    // // verifica se o grafo eh conexo
    // auto start = std::chrono::high_resolution_clock::now();
    // bool eh_conexo = graph.eh_conexo();
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    // if (eh_conexo) {
    //     std::cout << "O grafo " << ((direcionado == "true") ? "" : "não ") << "orientado eh conexo." << std::endl;
    // } else {
    //     std::cout << "O grafo " << ((direcionado == "true") ? "" : "não ") << "orientado eh desconexo." << std::endl;
    // }
    // std::cout << "Tempo de execucao: " << elapsed.count() << " nanosegundos." << std::endl;

    std::string instances[3] = {"grafo1.txt", "grafo2.txt", "grafo3.txt"};

    for(int i=0; i<3; i++){
        std::ifstream instance_file("./instances/" + instances[i]);
        if (!instance_file.is_open()) {
            std::cerr << "Nao foi possivel abrir o arquivo " << instances[i] << std::endl;
            continue;
        }

        std::cout << std::endl << "==========Testes com grafo de " << instances[i] << "=========" << std::endl;
        directed_test(instance_file);
        instance_file.clear(); // Limpa o estado de eof para permitir nova leitura
        instance_file.seekg(0); // Retorna ao inicio do arquivo
        undirected_test(instance_file);
    }
    return 0;
}
