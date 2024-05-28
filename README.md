# CppAutoControl
# Requerimentos: OpenCV
## Considerando a exigência de realizar o reconhecimento de imagem para automações em C++, desenvolvi o CppAutoControl. Este é uma versão inspirada no PyAutoGUI, porém otimizada para aproveitar a velocidade e os privilégios associados à linguagem de programação C++.

## Para a implementação do reconhecimento de imagem, foi utilizado o OpenCV. O funcionamento do sistema ocorre da seguinte maneira:

# Funções de imagem:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/45d1ca80-4c48-406d-bf1a-5c07b5069e9d)

### Passe o caminho para pasta onde você quer que a screenshot que vai ser analisada fique guardada.
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/0e16e50a-7f85-41ab-81a7-8cffef88f405)

<hr>

### Após isto voce pode utilizar funções para a analise da imagem como:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/43fa53b8-13cc-4bd1-9161-624f802d2a14)
### Os seguintes parametros terão que ser passados nesta função: 1- Caminho da imagem a ser analisada, 2- Caminho da imagem que você quer encontrar dentro da que será analisada, 3- Grau de confiança para determinar se a imagem foi encontrada ou nao com sendo 0.0 = 0% e 1.0 = 100%
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/b36bea26-0bed-4e50-ba75-88e9537f1b5b)
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/41ac7613-dff2-41d2-9633-4b852089b352)

<hr>

### Esta função era retonar os seguintes parametros: 1- Um booleano (True or False), 2- Se caso encontrada a imagem a posição X, Y em que ela se encontra.
### Vamos agora para uma demonstração simples de como usar esta função: 

![image](https://github.com/viniimiguel/cautoguii/assets/144070822/fb814bf4-4dc1-4367-ae68-8bb69b039a3f)

<hr>

# Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/0bbfafe4-12db-48d7-8af7-851b5c7e08db)

### Esta função ira tirar um screenshot da regiao desejada por exemplo você deve passar o caminho para salvar a screenshot e o X, Y que quer tirar captura como por exemplo:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/9ed2e045-4417-4261-b66f-769a206e0040)
### Neste exemplo eu estou tirando uma screenshot da região X:500 e Y:500 do meu monitor e salvando na variavel "caminho".

<hr>


# Funções de mouse:

![image](https://github.com/viniimiguel/cautoguii/assets/144070822/1f6741d1-77e4-442b-ac69-b917a7f50111)

## Função: 
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/212bcfbe-015c-4b1d-b126-99a113813f2e)

<hr>

### Nesta função você deverá passar apenas nos primeiros parametros a posição X, Y do a qual voce deseja que o mouse se mova e por ultimo o tempo de Duração deste movimento em milisegundos Por exemplo: ![image](https://github.com/viniimiguel/cautoguii/assets/144070822/5c9aac60-1572-4cf7-b6fc-cbf4b87d3051)
### Quero movimentar meu mouse para o X:100, Y:100 com a duração de 1 segundo.

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/ce4bfb61-68ff-4f9c-b41a-7f02d720e446)
### Nesta função voce deverá passar como parametro apenas o numero de quantas vezes você quer clicar e o tipo de botão como por exemplo "left", "right":
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/76d9db76-f2dc-4418-8039-009d08faf77e)

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/306c7fcf-8f09-4066-8e03-28a319e02c9b)

<hr>

### Nesta função voce deverá passar como parametro para onde voce quer arrastar seu mouse com X e Y e o tempo de duração por exemplo:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/ec90e225-5619-4a6e-b591-5291d73fd193)
### Neste exemplo o dragTo ira arrastar o seu mouse da posição em que ele estiver ir ate a posição X:100 e Y:100 com a duração de 1 segundo e soltar o click.

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/ab698b6f-b4bf-483e-be39-8127e280df7f)

### Esta função apenas lhe retornar um pair<int,int> da posição X, Y atual do seu mouse.
### Aqui está um exemplo simples de como usar esta função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/4eaeeef3-2015-4e67-b7c4-5e08a295f7cf)

![image](https://github.com/viniimiguel/cautoguii/assets/144070822/fbadc2f6-ceb8-456c-b594-07a134a09b71)

<hr>

# Funções de teclado:

## Função: 
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/34e48af8-d412-4df5-adab-2c4fc2f18406)
## Nesta função você de ve apenas declarar um char da tecla que voce quer pressionar:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/c100d567-8322-45e2-be19-0567b573ad47)
## A primeira tecla passada no parametro ira ser pressionada ate o fim do pressionamento da segunda tecla.

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/a5773c66-c893-4325-9688-cceb9a96ae8d)
## Nesta função você deverá declarar a tecla via hexadecimal como por exemplo: 
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/ade81c63-2e4d-4fac-8231-11552db80df1)
## Neste exemplo esta sendo simulado um "ALT + TAB" como hotkey.

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/1564231b-4476-4f32-ba56-a7714e57b8e7)
## Nesta função você deverá declarar um char como por exemplo 'A' e o numero de vezes que esta tecla sera pressionada como por exemplo:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/80b24448-81d7-4475-bb5c-09ec27704842)

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/92a30635-1d1a-4efc-93e6-a6fad3454984)
## Nesta função você deverá declarar em hexadecimal a tecla a ser pressionada e o numero de vezes que a mesma sera pressionada como por exemplo:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/7e95b362-5f29-4a1f-9577-2cf824b0f6ae)

<hr>

## Função:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/0fbb9781-7476-403b-9e8f-7cc696a1f917)
## Nesta função você deverá declarar uma string com oque voce quiser digitar como por exemplo:
![image](https://github.com/viniimiguel/cautoguii/assets/144070822/8316c7d3-d671-44db-9e71-c52f9674116c)

<hr>

# Se você leu até aqui, obrigado! Espero este projeto seja útil. Sinta-se à vontade para modificar o código de acordo com suas necessidades e preferências. Tenha um bom uso!

<hr>
