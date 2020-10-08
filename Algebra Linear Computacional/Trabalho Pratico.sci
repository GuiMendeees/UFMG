
Trabalho Prático Parte 1
In [28]:

import numpy as np
import math

Questão 1

Calcule as abscissas $t_i$ e os pesos $w_i$ via a matriz de Jacobi.
In [173]:

def jacobi(n):    
    # Iniciar a matriz J
    J = np.zeros((n,n))
    for i in range(n):
        for j in range(n):
            if (np.abs(i-j) == 1):
                k = np.ceil((i+j)/2)
                J[i,j] = np.sqrt((k**2)/(4*(k**2) - 1))
    # Calcular autovalores e autovetores
    autovalores, autovetores = np.linalg.eigh(J)
    # Ordenar em ordem decrescente do autovalor
    t = -np.sort(-autovalores)
    # Calcular w
    w = np.zeros(n)
    for i in range(n):
        w[i] = 2*autovetores[0,i]**2
    # Retornar t e w como vetores de dimensões 1 x n
    return t, w

In [174]:

ans2 = ([ 0.57735027, -0.57735027], [0.9999999999999998, 0.9999999999999998])
ans3 = ([ 7.74596669e-01, -4.78946310e-17, -7.74596669e-01], [0.5555555555555551, 0.8888888888888894, 0.5555555555555556])
ans4 = ([ 0.86113631,  0.33998104, -0.33998104, -0.86113631], [0.3478548451374544, 0.652145154862546, 0.6521451548625463, 0.3478548451374541])
assert np.allclose(ans2, jacobi(2))
assert np.allclose(ans3, jacobi(3))
assert np.allclose(ans4, jacobi(4))

Inicie os vetores difTab2, difTab3 e difTab4 com as diferenças entre os $t$s e $w$s encontrados para $n=2,3,4$ com os valores tabelados.
In [175]:

#difTab3[0][0] guarda t[0] - t0 tabelado pra n=3
#difTab3[0][1] guarda t[1] - t1 tabelado pra n=3
#difTab3[0][2] guarda t[2] - t2 tabelado pra n=3
#
#difTab3[1][0] guarda w[0] - w0 tabelado pra n=3
#difTab3[1][1] guarda w[1] - w1 tabelado pra n=3
#difTab3[1][2] guarda w[2] - w2 tabelado pra n=3
#...

difTab2 = np.zeros((2,2))
difTab3 = np.zeros((2,3))
difTab4 = np.zeros((2,4))

t,w = jacobi(2)
difTab2[0,0] = t[0] - (-0.5773502691)
difTab2[0,1] = t[1] - (0.5773502691)
difTab2[1,0] = w[0] - (1)
difTab2[1,1] = w[1] - (1)

t,w = jacobi(3)
difTab3[0,0] = t[0] - (-0.7745966692)
difTab3[0,1] = t[1] - (0)
difTab3[0,2] = t[2] - (0.7745966692)
difTab3[1,0] = w[0] - (0.5555555555)
difTab3[1,1] = w[1] - (0.8888888888)
difTab3[1,2] = w[2] - (0.5555555555)

t,w = jacobi(4)
difTab4[0,0] = t[0] - (-0.8611363115) 
difTab4[0,1] = t[1] - (-0.3399810435)
difTab4[0,2] = t[2] - (0.3399810435)
difTab4[0,3] = t[3] - (0.8611363115)
difTab4[1,0] = w[0] - (0.3478548451)
difTab4[1,1] = w[1] - (0.6521451548) 
difTab4[1,2] = w[2] - (0.6521451548)
difTab4[1,3] = w[3] - (0.3478548451)

In [176]:

print("difTab2: ", difTab2, "\n")
print("difTab3: ", difTab3, "\n")
print("difTab4: ", difTab4, "\n")

difTab2:  [[ 1.15470054e+00 -1.15470054e+00]
 [-2.22044605e-16 -2.22044605e-16]] 

difTab3:  [[ 1.54919334e+00 -4.51028104e-17 -1.54919334e+00]
 [ 5.55557822e-11  8.88884522e-11  5.55557822e-11]] 

difTab4:  [[ 1.72227262e+00  6.79962087e-01 -6.79962087e-01 -1.72227262e+00]
 [ 3.74541509e-11  6.25463015e-11  6.25459684e-11  3.74543174e-11]] 

In [ ]:


Questão 2
In [177]:

print(jacobi(2))
print(jacobi(3))
print(jacobi(4))

(array([ 0.57735027, -0.57735027]), array([1., 1.]))
(array([ 7.74596669e-01, -4.51028104e-17, -7.74596669e-01]), array([0.55555556, 0.88888889, 0.55555556]))
(array([ 0.86113631,  0.33998104, -0.33998104, -0.86113631]), array([0.34785485, 0.65214515, 0.65214515, 0.34785485]))

Porque para $n=2,3,4$ a soma dos pesos é igual a 2?

O vetor que passa pela primeira coordenada de cada autovetor possui norma 1. Isto é, o somatório das coordenadas ao quadrado é igual a 1.

Em cada posição de w estamos armazenando duas vezes cada primeira coordenada ao quadrado, então é de se esperar que o somatório dos valores presentes em w (pesos) resulte em 2.
Questão 3

Escreva uma função para calcular a integral pela quadratura de Gauss-Legendre.
In [179]:

# y é um vetor 1 x n em que y[i]=f(x[i])
# w é o vetor 1 x n obtido com a função jacobi
def gaussLegendre(y, n, a, b, w):
    ans = 0
    for i in range(n):
        ans += w[i] * y[i]
    ans = ans * ((b-a) / 2)
    return ans

Calcule $\int_0^2(x^5-x^3+x-1)dx$ usando $n=2$ na função de Gauss-Legendre que você criou.
In [180]:

a = 0
b = 2
n = 2
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = x[i]**5 - x[i]**3 + x[i] - 1
intGL2 = gaussLegendre(y,n,a,b,w)

In [181]:

assert np.isclose(5.777777777777776, intGL2)

Calcule $\int_0^2(x^5-x^3+x-1)dx$ usando $n=3$ na função de Gauss-Legendre que você criou.
In [182]:

a = 0
b = 2
n = 3
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = x[i]**5 - x[i]**3 + x[i] - 1

intGL3 = gaussLegendre(y,n,a,b,w)

In [183]:

assert np.isclose(6.6666666666666625, intGL3)

Calcule $\int_0^2(x^5-x^3+x-1)dx$ usando $n=4$ na função de Gauss-Legendre que você criou.
In [184]:

a = 0
b = 2
n = 4
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = x[i]**5 - x[i]**3 + x[i] - 1

intGL4 = gaussLegendre(y,n,a,b,w)

In [185]:

assert np.isclose(6.666666666666674, intGL4)

Explique os resultados obtidos para $\int_0^2 (x^5-x^3+x-1) dx$ com $n = 2,3,4$.

O resultado exato da integral definida da função no intervalo de 0 até 2 é 20/3 = 6.666666666666667. Ao realizar o cálculo pelo método de Gauss-Legendre espera-se obter um valor aproximado a 20/3 e ao aumentar o valor do grau do polinômio espera-se que o valor encontrado seja cada vez mais próximo a 20/3. O que é acontece é exatamente isso: para n=2 temos 5.777777777777776; para n=3 temos 6.6666666666666625 e para n=4 temos 6.666666666666674.
Questão 4

Qual o valor exato de $\int_0^\pi \sin(x) dx$?
In [186]:

## integral definida = derivada de sin(x) para pi - derivada de sin(x) para 0
## derivada de sin(x) = -cos(x)
exact = -np.cos(np.pi) - (-np.cos(0))

In [ ]:


Inicie o vetor difExac com as diferenças entre os valores encontrados para $n=3,4,5$ e o valor exato.
In [187]:

difExac = np.zeros(3)

a = 0
b = np.pi

n = 3
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = np.sin(x[i])
difExac[0] = exact - gaussLegendre(y,n,a,b,w)

n = 4
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = np.sin(x[i])
difExac[1] = exact - gaussLegendre(y,n,a,b,w)

n = 5
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = np.sin(x[i])
difExac[2] = exact - gaussLegendre(y,n,a,b,w)

In [ ]:


In [188]:

print(difExac)

[-1.38891361e-03  1.57715423e-05 -1.10284473e-07]

Questão 5

Seja $f(x)=e^x$. Avalie $f(x)$ em $x_0=-\frac{\sqrt{3}}{3}$ e $x_1=\frac{\sqrt{3}}{3}$.
In [189]:

y = np.zeros(2)
x = np.zeros(2)
x[0] = -np.sqrt(3)/3
x[1] = np.sqrt(3)/3
y[0] = np.exp(x[0])
y[1] = np.exp(x[1])

In [ ]:


In [190]:

print(y)

[0.56138391 1.78131217]

Determine o polinômio linear $p(x)$ que passa pelos pontos ($x_0$,y[0]) e ($x_1$,y[1]).
In [191]:

#p[0] guarda o coeficiente de x^0
#p[1] guarda o coeficiente de x^1
p = np.zeros(2)
p[1] = (y[1] - y[0])/(x[1] - x[0])
p[0] = y[0] - p[1]*x[0]

In [192]:

print(p)

[1.17134804 1.05648886]

In [ ]:


Calcule analiticamente $\int_{-1}^1p(x)dx$.
In [193]:

integAn = np.exp(1) - np.exp(-1)

In [ ]:


Agora calcule $\int_{-1}^1e^xdx$ usando $n=2$ na função de Gauss-Legendre que você criou.
In [194]:

a = -1
b = 1
n = 2
t,w = jacobi(n)
x = np.zeros(n)
y = np.zeros(n)
for i in range(n):
    x[i] = a + ((b - a) / 2) * (t[i] + 1)
for i in range(n):
    y[i] = np.exp(x[i])

integGL = gaussLegendre(y,n,a,b,w)

In [ ]:


In [195]:

print(integGL - integAn)

-0.007706299377872483

Explique os resultados.

    Temos que os valores exatos para f(x) são: -e^(-sqrt(3)/3) = 0.56138391379 -e^(sqrt(3)/3) = 1.78131217411 Encontramos o polinômio 1.05648886x + 1.17134804, portanto teremos: 1.05648886(-sqrt(3)/3) + 1.17134804 = 0.56138391228 1.05648886*(sqrt(3)/3) + 1.17134804 = 1.78131216772 Vemos que os resultados são bem próximos, o que nos diz que o polinômio encontrado se aproxima bem da função original.

2. Notamos que o método de Gauss-Legendre nos dá uma boa aproximação do valor real da integral de e^x no intervalo entre -1 e 1 escolhendo n = 2, pois o erro encontrado foi de aproximadamente 0,008. Uma alternativa para diminuir o erro seria aumentar o valor de n (grau do polinômio).
