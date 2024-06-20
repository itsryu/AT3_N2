<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">

<body>
    <div id="container">
        <div align="center" style="display: inline_block">
            <h1>Torre de Hanói</h1>
            <p>Este é um jogo de console desenvolvido utilizando a linguagem de programação C.</p>
        </div>
        <div>
            <h2>Sobre o jogo</h2>
            <p>
            A Torre de Hanói é um dos mais famosos jogos de Matemática. Ele consiste de uma base contendo três pilares (hastes), em um dos quais está disposta uma torre formada por alguns discos de diâmetros diferentes, furados no centro e colocados uns sobre os outros, em ordem crescente de diâmetro, de cima para baixo. O número de discos pode variar.
            </p>
            <h2>Regras</h2>
            <ol>
                <li>Você só pode mover apenas 1 disco por vez.</li>
                <li> Um disco com diâmetro maior nunca pode ficar sobre um disco com diâmetro menor.</li>
            </ol>
            <h2>Como Usar</h2>
            <ol>
                <div style="padding: 10px; border: 1px solid #f5c6cb; background-color: #f8d7da; color: #721c24; border-radius: 5px;">
                    <strong>Atenção:</strong> Este programa foi desenvolvido para plataformas Windows, tentar executa-lo em outra plataforma acarretará em erros de compilação. 
                </div>
                </br>
                <li>
                    <strong>Clonar o repositório:</strong> Para clonar o repositório, execute o seguinte comando em seu
                    terminal (Obs: necessário ter o <a href="https://git-scm.com/downloads">git</a> instalado em sua
                    máquina):
                    <pre><code>git clone https://github.com/itsryu/AT3_N2.git && cd AT3_N2</code></pre>
                </li>
                <li>
                    <strong>Compilação:</strong> Vá para a pasta AT3_N2 dentro de onde o projeto foi clonado e execute o arquivo windows.bat (Windows):
                    <pre><code>windows.bat</code></pre>
                </li>
                <li>
                    <strong>Compilação:</strong> Ou se quiser compilar utilizando linha de comando abra um terminal na pasta AT2_N2 dentro de onde o projeto foi clonado e compile o
                    programa utilizando o GCC (GNU Compiler Collection):
                    <pre><code>gcc ./functions/functions.c ./functions/game.c ./functions/menu.c ./main.c -o main.exe</code></pre>
                </li>
                <li>
                    <strong>Execução:</strong> Após a compilação, execute o arquivo 'main.exe' para inicializar o
                    programa.
                    <pre><code>main.exe</code></pre>
                </li>
                <li><strong>Interagindo com o programa:</strong> Siga as instruções do menu para realizar as ações
                    desejadas.</li>
            </ol>
            <h2>Ferramentas de desenvolvimento utilizadas</h2>
            <ol>
                <li><strong>Visual Studio Community 2022</strong> (Utilizada para o desenvolvimento e depuração do
                    código)</li>
                <li><strong>GitHub</strong> (Utilizada para o versionamento)</li>
            </ol>
        </div>
    </div>
</body>

</html>
