# 2. Termo de Abertura do Projeto

Este tópico representa o Termo de Abertura de Projeto (TAP) para o desenvolvimento do carrinho 
seguidor de linha, como parte do Projeto Integrador de Engenharia 1 (PI1) da Faculdade UnB Gama (FGA).<br>
O objetivo deste TAP é estabelecer uma base sólida para a execução eficiente do projeto, 
definindo seus objetivos, escopo, requisitos e diretrizes.
___________________________________________________________________________________

## 2.1 Dados do projeto

- Nome do Projeto: K.A.T.I.A.U
- Data de abertura: 15/04/2024
- Código: 1-A
- Patrocinador: Universidade de Brasília
- Gerente Geral: Pedro Miguel Martins de Oliveira dos Santos/200059980 
    - trabalhos.pedromiguel@gmail.com
    - (61) 99211-2442
- Gerente de Software: Samuel Nogueira Bacelar/180130722
    - 180130722@aluno.unb.br
    - (61) 99996-4690
- Gerente de Hardware: Pedro Augusto Vieira Zago/211031815
    - pedroaugustopz@hotmail.com 
    - (61) 99927-1301
- Gerente de Energia: Mayratan Araujo dos Reis/202045606
    - mayratan10@gmail.com 
    - (61) 99308-5482  
- Gerente de Estruturas: Cauan Victor Macedo Ataides Martins/222037601
    - 222037601@aluno.unb.br
    - (63) 99265-2147

___________________________________________________________________________________

## 2.2 Objetivos

O projeto do carrinho seguidor de linha estabelece 4 principais objetivos SMART
(Específicos, Mensuráveis, Alcançáveis, Relevantes e Temporais) que guiarão suas ativi-
dades e direcionarão seus esforços para alcançar resultados concretos e mensuráveis.

### 2.2.1 Trajetos Completos

O primeiro objetivo do projeto é garantir que o carrinho seja capaz de percorrer
completamente três trilhas marcadas no chão.<br> 
Isso significa que o carrinho deverá ser capaz de seguir com precisão o trajeto estabelecido,
mantendo-se sobre a linha preta, sem sair do percurso, e completar com sucesso cada uma das 
três trilhas definidas.<br> 
Este objetivo é mensurável pelo número de trilhas completadas com sucesso durante os testes
e apresentações do carrinho.

### 2.2.2 Proteção do Ovo

O segundo objetivo concentra-se na integridade do ovo de galinha que o carrinho
carregará durante os trajetos.<br> 
O objetivo é garantir que o ovo não seja danificado ao longo dos percursos, 
demonstrando a capacidade do carrinho de manter uma condução suave e
estável.<br> 
Isso será mensurado pela condição do ovo ao final de cada trajeto, verificando se
permanece íntegro e sem danos significativos.

### 2.2.3 Desempenho Temporal

O terceiro objetivo do projeto é otimizar o tempo de percurso do carrinho.<br>
Isso implica completar os trajetos no menor tempo possível, demonstrando eficiência 
e velocidade no deslocamento do carrinho.<br> 
Este objetivo é mensurável pelo tempo registrado para cada trajeto, 
desde o início até a conclusão, durante os testes e competições.

### 2.2.4 Autonomia e Funcionalidade

O quarto objetivo do projeto é assegurar que o carrinho seja totalmente autônomo
e operacional, sem a necessidade de controle externo durante os trajetos.<br>
Isso significa que o carrinho deve ser capaz de iniciar, percorrer os trajetos e completar 
as tarefas propostas sem intervenção humana ou controle remoto.<br>
Este objetivo é mensurável pela demonstração da autonomia do carrinho durante os testes 
e apresentações, verificando sua capacidade de funcionar de forma independente.

___________________________________________________________________________________

## 2.3 Mercado-alvo

O mercado-alvo do carrinho seguidor de linha abrange uma variedade de segmentos 
e públicos potenciais. Instituições de ensino, incluindo escolas, universidades e centros
de pesquisa, representam um importante mercado consumidor, buscando soluções educacionais 
inovadoras para o ensino de conceitos de robótica, automação e programação.<br>
Além disso, empresas de tecnologia e robótica podem se interessar pelo carrinho como
uma ferramenta de pesquisa e desenvolvimento ou para integração em seus próprios produtos.<br>
Hobbistas e entusiastas de robótica também constituem um mercado significativo,
buscando oportunidades para construir e experimentar novos projetos.<br>
O setor industrial pode encontrar aplicação para o carrinho em ambientes de 
produção automatizada ou logística interna.<br>
Competições de robótica locais, regionais e internacionais também
representam um mercado-alvo importante, onde equipes podem competir usando seus
próprios carrinhos seguidores de linha.<br> 
Em resumo, o carrinho seguidor de linha tem o potencial de atender a uma ampla 
gama de necessidades e interesses, tanto no ambiente educacional 
quanto no mercado comercial e de competições.

___________________________________________________________________________________

## 2.4 Requisitos

Os requisitos funcionais e não funcionais coletados para o desenvolvimento do
carrinho seguidor de linha serão apresentados nas Tabelas 1 e 2 a seguir:

___________________________________________________________________________________

### Tabela 1 - Requisitos Funcionais

| Id do Requisito | Engenharia Relacionada | Descrição do Requisito |
| ----- | ------------------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
| RF01  | Eletrônica          | O carrinho seguidor de linha requer uma fonte de energia <br> confiável e durável para sustentar os motores, sensores <br> e demais componentes eletrônicos ao longo do percurso.                                                                                                                            |
| RF02  | Eletrônica          | O carrinho seguidor de linha deve possuir um sistema de <br> aquisição para movimento que verifique se ele está <br> seguindo a linha demarcada no chão ou não.                                                                                                                                                |
| RF03  | Eletrônica          | O carrinho seguidor de linha deve possuir um sistema de <br> movimento para possibilitar que o carrinho se <br> movimente  de forma autônoma.                                                                                                                                                                |
| RF04  | Eletrônica          | O carrinho seguidor de linha deve possuir uma fonte <br> de energia confiável e durável para alimentar os motores, <br> os sensores e outros componentes eletrônicos do <br> carrinho durante toda a execução do percurso.                                                                                     |
| RF05  | Eletrônica          | O carrinho seguidor de linha deve possuir um sistema de <br> medição dos dados de posição, velocidade e aceleração <br> do carrinho.     |
| RF06  | Eletrônica          | O carrinho seguidor de linha deve possuir um sistema de <br> comunicação para facilitar a interação entre o <br> carrinho e a aplicação de análise de dados do carrinho. |
| RF07  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve exibir a distância percorrida <br> pelo carrinho. |
| RF08  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve exibir a trajetória percorrida <br> pelo carrinho. |
| RF09  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve exibir o tempo de percurso do carrinho.                          |
| RF10  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve exibir a velocidade e aceleração do carrinho.                    |
| RF11  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve calcular e exibir o consumo de energia do <br> carrinho.         |
| RF12  | Software            | A aplicação de análise de dados do carrinho seguidor de <br> linha deve exibir um dashboard com gráficos e dados <br> tratados.          |
| RF13  | Software            | O usuário, ao interagir com a aplicação de análise de <br> dados do carrinho seguidor de linha, deve ser capaz de <br> visualizar um histórico dos dados coletados na aplicação,<br> permitindo a análise de longo do tempo.                                                                                  |
| RF14  | AeroEspacial        | A estrutura do carrinho seguidor de linha deve ser capaz <br> de comportar todos os componentes eletrônicos.                             |
| RF15  | AeroEspacial        | A estrutura do carrinho seguidor de linha deve ser capaz <br> de carregar um ovo sem danifica-lo.                                        |
| RF16  | AeroEspacial        | A estrutura do carrinho seguidor de linha deve possuir <br> rodas capazes de se movimentar em todas as direções.                         |
| RF17  | AeroEspacial        | A estrutura do carrinho seguidor de linha não deve <br> possuir mecanismo de sucção.                                                     |
| RF18  | AeroEspacial        | A estrutura do carrinho seguidor de linha deve manter <br> sua integridade durante todo o percurso.                                      |
| RF19  | AeroEspacial        | A estrutura do carrinho seguidor de linha não deve <br> inclinar.                                                                        |
| RF20  | AeroEspacial        | A estrutura do carrinho seguidor de linha deve manter <br> seus sensores próximos ao solo em todo o percurso.                            |
| RF21  | AeroEspacial        | A estrutura do carrinho seguidor de linha não deve <br> possuir peso suficiente para o carrinho ficar estático ou <br> não possuir torque para sair da inércia.                                                                                                                                                    |
| RF22  | Energia, Eletrônica | O carrinho seguidor de linha deve preferencialmente <br> possuir uma bateria recarregável. Assim, o carrinho <br> poderá ser recarregado quando a energia estiver baixa,<br> garantindo que esteja sempre pronto para operar.                                                                                     |
| RF23  | Energia, Eletrônica | O carrinho seguidor de linha deve possuir um sistema de <br> monitoramento da carga da bateria que forneça <br> feedback em tempo real sobre o nível de energia <br> disponível,  permitindo  que o usuário ou o sistema de <br> controle tomem medidas preventivas, como recarregar a <br> bateria se necessário.                                                                                                                                                              |
| RF24  | Energia             | O carrinho seguidor de linha deve possuir um sistema de <br> gestão de energia eficiente que distribua a energia de <br> forma otimizada para os diferentes componentes do <br> carrinho, priorizando o funcionamento dos motores e <br> dos sensores essenciais.                                                 |

___________________________________________________________________________________

### Tabela 2 - Requisitos Não-Funcionais

| Id do Requisito | Engenharia Relacionada | Descrição do Requisito |
| ------------- | ------------- | ------------- |
| RNF01  | Eletrônica | Microcontrolador utilizado no carrinho seguidor de <br> linha será um ArduinoUno R3 pela sua versatilidade. |
| RNF02  | Eletrônica | O sensor infravermelho utilizado no carrinho seguidor <br> de linha para verificar se ele segue a linha ou não será <br> o TCRT5000, pelo seu custo e tamanho. |
| RNF03  | Eletrônica, Software | O meio de comunicação entre o carrinho e a aplicação <br> de análise de dados será Bluetooth, pela facilidade em <br> enviar e receber dados. |
| RNF04  | Eletrônica | Os sensores utilizados para medição de velocidade, <br> aceleração e posição serão dois sensores encoder, pela <br> facilidade de trabalho. |
| RNF05  | Eletrônica | O sensor para medição de corrente elétrica será o <br> ACS712. |
| RNF06  | Eletrônica | O motor utilizado deve ser de 6V com redução. |
| RNF07  | Software | A aplicação de análise de dados do carrinho seguidor <br> de linha deve ser responsiva e rápida, com um tempo <br> de resposta curto para garantir uma experiência do <br> usuário ágil. |
| RNF08  | Software | A interface da aplicação de análise de dados do carrinho <br> seguidor de linha deve ser amigável e de fácil <br> visualização. |
| RNF09  | Software | A aplicação de análise de dados do carrinho seguidor de <br> linha deve ser uma aplicação web. |
| RNF10  | Software | A aplicação de análise de dados do carrinho seguidor de <br> linha deve poder armazenar os dados criados pelos <br> sensores em um banco de dados. |
| RNF11  | AeroEspacial | O material utilizado no carrinho seguidor de linha deve <br> ser resistente para manter sua integridade durante o <br> percurso. |
| RNF12  | AeroEspacial | A quantidade e o tipo de rodas do carrinho seguidor de <br> linha deve permitir que o carrinho ande em todas as <br> direções |
| RNF13  | AeroEspacial | As rodas do carrinho seguidor de linha devem possuir <br> uma superfície que consiga aplicar atrito suficiente para <br> colocar o carrinho em movimento. |
| RNF14  | AeroEspacial | A localização do ovo no do carrinho seguidor de linha <br> deve ser planejada de forma que seja de fácil acesso ao <br> usuário e que mantenha a integridade do ovo por todo <br> o percurso. |
| RNF15  | AeroEspacial | A localização dos componentes eletrônicos do carrinho <br> seguidor de linha deve ser planejada considerando a <br> otimização do espaço e o fácil acesso para manutenção. |
| RNF16  | Energia | O sistema de energia do carrinho seguidor de linha deve <br> ser projetado para ser eficiente em termos de consumo <br> de energia, maximizando a vida útil da bateria e a <br> autonomia do carrinho durante a execução do percurso. |
| RNF17  | Energia | Os componentes do sistema de energia do carrinho <br> seguidor de linha devem ser leves e compactos para <br> minimizar    o peso total do carrinho e permitir uma fácil <br> integração em sua estrutura. |
| RNF18  | Energia, Eletrônica | Os componentes eletrônicos do carrinho seguidor de <br> linha devem possuir uma voltagem estável e consistente, <br> evitando flutuações que possam afetar negativamente o <br> desempenho ou a vida útil dos dispositivos. |
| RNF19  | Energia, AeroEspacial | O sistema de energia do carrinho seguidor de linha <br> deve ser projetado de forma que seja fácil de acessar e <br> manter, permitindo a substituição rápida de baterias <br>ou outros componentes quando necessário, sem <br> interromper significativamente a operação do carrinho. |
| RNF20  | Energia, Eletrônica | O sistema de energia do carrinho seguidor de linha deve <br> ser projetado de forma a possuir medidas de segurança <br> adequadas para protege-lo contra sobrecargas, <br> curto-circuitos e outras condições adversas que possam <br> representar riscos de segurança para o usuário ou <br> danificar os componentes do carrinho. |

___________________________________________________________________________________

## 2.5 Justificativa

O projeto do carrinho seguidor de linha surge em um contexto de busca por solu-
ções educacionais dinâmicas e eficazes, especialmente no campo da robótica e automação.<br>
Ao participar do Projeto Integrador de Engenharia 1 (PI1) da Faculdade UnB Gama
(FGA), reconhece-se a importância de desenvolver projetos que não apenas apliquem
os conhecimentos adquiridos, mas também contribuam de maneira significativa para o
aprendizado e o desenvolvimento dos alunos.<br>
O carrinho seguidor de linha, nesse sentido, representa uma oportunidade de de-
senvolvimento de soluções multifacetadas, capazes de gerar impacto tanto no ambiente
acadêmico quanto no mercado comercial e de competições; e uma oportunidade de unir
teoria e prática, estimulando a criatividade, o pensamento crítico e a resolução de problemas.<br>
Embora não surja diretamente da necessidade de preencher uma lacuna específica
no ensino, o projeto se fundamenta na busca por uma abordagem prática e envolvente
para o aprendizado de conceitos complexos de engenharias.<br>
Dessa forma, o objetivo não é apenas construir um carrinho funcional, mas também proporcionar uma 
experiência educacional enriquecedora e inspiradora para os participantes do projeto, contribuindo para
a formação de profissionais capacitados e inovadores.

___________________________________________________________________________________

## 2.6 Indicadores

- Na região do Distrito Federal e arredores, foram identificados eventos significati-
vos relacionados à área da robótica, como o "Festival SESI de Educação"e a "Competição
Brasileira de Robótica", além de feiras menores que também promovem essas atividades,
como os projetos apresentados durante a Semana Universitária da UNB.
- No que diz respeito aos projetos de pesquisa em robótica, foi observada uma
demanda considerável, principalmente originada de instituições de ensino, exemplificada
por projetos de extensão oferecidos pela UNB através do SIGAA.
- Após pesquisas, foram verificadas uma ampla diversidade no ensino de robó-
tica na região, abrangendo desde a educação básica até o ensino superior em Tecnologia
da Informação (TI). Também foram identificados a presença de 520 escolas SESI e 199
instituições de ensino superior em TI na região.
- Ao examinarmos o panorama das empresas com interesse no mercado de robó-
tica, foram constatados a presença de 14 empresas de grande e médio porte nos arredores
do Distrito Federal, segundo uma lista das maiores empresas do setor no Brasil.
- Eventos e seminários voltados para a educação e tecnologia também foram
identificados na região do Distrito Federal, como o SEEDF, realizado nos dias 17 e 19 de
outubro de 2023, de forma híbrida, no auditório da Escola Técnica do Guará.

___________________________________________________________________________________

## Tabela 3 - Histórico de Revisão

| Data  |             Descrição           |              Autor            |             Revisor           |
|       |---------------------------------|-------------------------------|-------------------------------|
| 02/05 | Criação do cronograma           | [Brunna Louise](https://github.com/brunna-martins) | [Pedro Miguel](https://github.com/pedroMADBR) |
| 01/06 | Correção de RF de Software | [Pedro Miguel](https://github.com/pedroMADBR) | [Brunna Louise](https://github.com/brunna-martins) |

___________________________________________________________________________________