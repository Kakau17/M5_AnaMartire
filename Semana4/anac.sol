// Passo 1 (5 pontos): Adicione uma variável de estado ao contrato: idade.
// Considere que por padrão uma instância deste contrato é de uma
// pessoa com 18 anos de idade. Adicione comentários ao código.

// Passo 2 (4 pontos): Desenvolva uma função "setIdade", que recebe um
// valor e atribui este valor à variável idade. Também desenvolva uma
// função "getIdade" que retorna o valor da variável idade. Adicione
// comentários ao código.

// Ir além (1 ponto): Adicione uma variável que armazena o endereço
// do dono do contrato. Utilize esta variável para fazer com que a
// função "setIdade“ seja somente executadas pelo dono do contrato.

// SPDX-License-Identifier: MIT
pragma solidity >=0.6.12 <0.9.0;

contract Anac { //criação de contrato "Anac"
    uint idade; //variável de estado (declara uma variável que será utilizada depois)
    address public owner; //variável pública que armazena o endereço do dono do contrato

    constructor() {
        idade = 18; //sempre que o contrato for iniciado, a idade será 18 por padrão
        owner = msg.sender; //somente quem for definido como "owner" pode executar alguma função (msg.sender é o endereço de quem subiu o contrato)
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Bro ur not the owner -_-"); //verifica se a pessoa que está mexendo no código agora é o usuário que iniciou o código. caso não, a mensagem na string aparece
        _; //indica que há mais código depois dessa função "modifier"
    }

    function setIdade(uint _idade) external returns(bool) { //qualquer um pode colocar a idade que quiser, e essa função vai retornar um true ou false
        idade = _idade; //a idade inicial (18 anos) será trocada pela colocada (_idade)
        return true; //assim que isso tudo for feito, a função retorna "true"
    }

}