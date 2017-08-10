%Camada de entrada
x = [0;0];
Wo = [5 -5; -5 5]; %Camada oculta
Wbo = [ -2; -2 ]; %Camada de bias oculta
%Potencial de ação da camada oculta
ao = Wo'*x + Wbo;
%Saída da camada oculta
yo = 1./(1+exp(-ao));
%Pesos da camada de saída
Ws = [10;10];
Wbs = [-8; -8];
%Potencial de ação da camada de saída
as = Ws'*yo + Wbs
%Saída da camada de saída
ys = 1./(1+exp(-as))
