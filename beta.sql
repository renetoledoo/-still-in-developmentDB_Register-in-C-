CREATE DATABASE	REGISTRO;

USE REGISTRO;
CREATE TABLE PRODUTOS (
	idProdutos INT AUTO_INCREMENT PRIMARY KEY, 
    nome varchar(150) not null, 
	descricao varchar(100) not null,
   quantidade int not null
) ENGINE = InnoDB;

drop table pessoa;


create table P_PESSOA_NOVA (

	idPessoa int AUTO_INCREMENT primary key,
    P_USER varchar(30) not null,
    P_SENHA varchar(10) not null,
    nome varchar(100) not null,
    sobrenome varchar(100) not null,
    idade int not null,
    sexo enum('F', 'M')
);

create table P_CARGO (
	idCargo int auto_increment primary key,
    NOME VARCHAR(100),
    SALARIO DECIMAL(10,2)
);

INSERT INTO P_PESSOA_NOVA (P_USER, P_SENHA, nome, sobrenome, idade, sexo) VALUES ("rteste", "r123", "rene", "toledo", 20 , "M");
INSERT INTO P_PESSOA_NOVA (P_USER, P_SENHA, nome, sobrenome, idade, sexo) VALUES ("rbraga", "r123", "braga", "toledo", 20 , "M");
INSERT INTO P_PESSOA_NOVA (P_USER, P_SENHA, nome, sobrenome, idade, sexo) VALUES ("rtestando", "r123", "toledo", "braga", 20 , "M");

select * from p_pessoa_nova;
DELIMITER @

CREATE PROCEDURE sp_VALIDANDO(
sp_user VARCHAR(50)
)
BEGIN

	IF NOT EXISTS( SELECT * FROM P_PESSOA_NOVA WHERE P_USER = p_user ) THEN
		INSERT INTO P_PESSOA (P_PESSOA, P_SENHA, P_NOME) VALUES (P_PESSOA, P_SENHA, nome)
		
    END IF
END@
