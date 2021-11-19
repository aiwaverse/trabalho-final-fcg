#version 330 core

// Atributos de fragmentos recebidos como entrada ("in") pelo Fragment Shader.
// Neste exemplo, este atributo foi gerado pelo rasterizador como a
// interpolação da posição global e a normal de cada vértice, definidas em
// "shader_vertex.glsl" e "main.cpp".
in vec4 position_world;
in vec4 normal;

// Posição do vértice atual no sistema de coordenadas local do modelo.
in vec4 position_model;

// Coordenadas de textura obtidas do arquivo OBJ (se existirem!)
in vec2 texcoords;

// Modelo de interpolação do Gouraud
in vec3 gouraud_shading;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Identificador que define qual objeto está sendo desenhado no momento
#define SPHERE 0
#define RIFLE  1
#define PLANE  2
#define CUBE   3
#define PLANE_WALL 4
#define HUD 5
#define TARGET 6
#define SKYBOX 7
uniform int object_id;

// Parâmetros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;

// Variáveis para acesso das imagens de textura
uniform sampler2D TextureImage0;
uniform sampler2D TextureImage1;
uniform sampler2D TextureImage2;
uniform sampler2D TextureImage3;
uniform sampler2D TextureImage4;
uniform sampler2D TextureImage5;
uniform sampler2D TextureImage6;

// O valor de saída ("out") de um Fragment Shader é a cor final do fragmento.
out vec4 color;

// Constantes
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    // Obtemos a posição da câmera utilizando a inversa da matriz que define o
    // sistema de coordenadas da câmera.
    vec4 origin = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 camera_position = inverse(view) * origin;

    // O fragmento atual é coberto por um ponto que percente à superfície de um
    // dos objetos virtuais da cena. Este ponto, p, possui uma posição no
    // sistema de coordenadas global (World coordinates). Esta posição é obtida
    // através da interpolação, feita pelo rasterizador, da posição de cada
    // vértice.
    vec4 p = position_world;

    // Normal do fragmento atual, interpolada pelo rasterizador a partir das
    // normais de cada vértice.
    vec4 n = normalize(normal);
    if (object_id == SKYBOX)
        n = normalize(-normal);

    // Vetor que define o sentido da fonte de luz em relação ao ponto atual.
    vec4 l = normalize(camera_position - p);

    // Vetor que define o sentido da câmera em relação ao ponto atual.
    vec4 v = normalize(camera_position - p);

    // Vetor que define o sentido da reflexão especular ideal.
    vec4 r = -l + 2*n*(dot(n, l));// PREENCHA AQUI o vetor de reflexão especular ideal

    // Parâmetros que definem as propriedades espectrais da superfície
    vec3 Kd; // Refletância difusa
    vec3 Ks; // Refletância especular
    vec3 Ka; // Refletância ambiente
    float q; // Expoente especular para o modelo de iluminação de Phong

    // Coordenadas de textura U e V
    float U = 0.0;
    float V = 0.0;

    if ( object_id == SPHERE || object_id == SKYBOX)
    {
        // PREENCHA AQUI as coordenadas de textura da esfera, computadas com
        // projeção esférica EM COORDENADAS DO MODELO. Utilize como referência
        // o slides 134-150 do documento Aula_20_Mapeamento_de_Texturas.pdf.
        // A esfera que define a projeção deve estar centrada na posição
        // "bbox_center" definida abaixo.

        // Você deve utilizar:
        //   função 'length( )' : comprimento Euclidiano de um vetor
        //   função 'atan( , )' : arcotangente. Veja https://en.wikipedia.org/wiki/Atan2.
        //   função 'asin( )'   : seno inverso.
        //   constante M_PI
        //   variável position_model

        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;

        vec4 p = position_model - bbox_center;

        float rho = length(p);
        float theta = atan(p.x, p.z);
        float phi = asin(p.y/rho);

        U = (theta + M_PI)/(2*M_PI);
        V = (phi + M_PI/2)/M_PI;
    }
    else if ( object_id == RIFLE  || object_id == CUBE || object_id == TARGET)
    {
        // PREENCHA AQUI as coordenadas de textura do coelho, computadas com
        // projeção planar XY em COORDENADAS DO MODELO. Utilize como referência
        // o slides 99-104 do documento Aula_20_Mapeamento_de_Texturas.pdf,
        // e também use as variáveis min*/max* definidas abaixo para normalizar
        // as coordenadas de textura U e V dentro do intervalo [0,1]. Para
        // tanto, veja por exemplo o mapeamento da variável 'p_v' utilizando
        // 'h' no slides 158-160 do documento Aula_20_Mapeamento_de_Texturas.pdf.
        // Veja também a Questão 4 do Questionário 4 no Moodle.

        float minx = bbox_min.x;
        float maxx = bbox_max.x;

        float miny = bbox_min.y;
        float maxy = bbox_max.y;

        float minz = bbox_min.z;
        float maxz = bbox_max.z;

        U = (position_model.x - minx)/(maxx - minx);
        V = (position_model.y - miny)/(maxy - miny);
    }
    else if ( object_id == PLANE || object_id == HUD || object_id == PLANE_WALL )
    {
        // Coordenadas de textura do plano, obtidas do arquivo OBJ.
        U = texcoords.x;
        V = texcoords.y;
    }

    // Alpha default = 1 = 100% opaco = 0% transparente
    color.a = 1;

    // Obtemos a refletância difusa a partir da leitura da imagem TextureImage0
    vec3 KdSphere = texture(TextureImage0, vec2(U,V)).rgb;
    vec3 KdPlane = texture(TextureImage1, vec2(U,V)).rgb;
    vec3 KdRifle = texture(TextureImage2, vec2(U,V)).rgb;
    vec3 KdCube = texture(TextureImage3, vec2(U,V)).rgb;
    vec4 KdHUD = texture(TextureImage4, vec2(U,V)).rgba; // Obtemos RGBA da textura do HUD
    vec3 KdTarget = texture(TextureImage5, vec2(U, V)).rgb;
    vec3 KdSkybox = texture(TextureImage6, vec2(U, V)).rgb;

    // Equação de Iluminação
    float lambert = max(0,dot(n,l));
    if (object_id == RIFLE)
    {
        Kd = KdRifle * (lambert + 2.0);
        Ks = vec3(0.8,0.8,0.8);
        Ka = vec3(0.0,0.0,0.0);
        q = 32.0;
    }
    else if (object_id == PLANE)
    {
        Kd = KdPlane * (lambert + 0.01);
        Ks = vec3(0.3,0.3,0.3);
        Ka = vec3(0.0,0.0,0.0);
        q = 20.0;
    }
    else if (object_id == PLANE_WALL)
    {
        Kd = KdCube * (lambert + 0.01);
        Ks = vec3(0.3,0.3,0.3);
        Ka = vec3(0.0,0.0,0.0);
        q = 20.0;
    }
    else if (object_id == CUBE)
    {
        Kd = KdCube * (lambert + 0.01);
        Ks = vec3(0.3,0.3,0.3);
        Ka = vec3(0.0,0.0,0.0);
        q = 20.0;
    }
    else if (object_id == SPHERE)
    {
        // TOTALMENTE DIFUSA
        Kd = KdSphere * (lambert + 0.01);
        Ka = vec3(0.0, 0.0, 0.0);
        Ks = vec3(0.0, 0.0, 0.0);
        q = 20.0;
    }
    else if (object_id == SKYBOX)
    {
        // TOTALMENTE DIFUSA
        Kd = KdSkybox * (lambert + 0.01);
        Ka = vec3(0.0, 0.0, 0.0);
        Ks = vec3(0.0, 0.0, 0.0);
        q = 20.0;
    }
    else if (object_id == TARGET)
    {
        Kd = KdTarget * (lambert + 0.01);
        Ks = vec3(0.3,0.3,0.3);
        Ka = vec3(0.0,0.0,0.0);
        q = 20.0;
    }
    else if (object_id == HUD)
    {
        color.rgba = KdHUD;
        return;
    }
        // Espectro da fonte de iluminação
    vec3 I = vec3(1.0,1.0,1.0); // PREENCH AQUI o espectro da fonte de luz

    // Espectro da luz ambiente
    vec3 Ia = vec3(0.2,0.2,0.2); // PREENCHA AQUI o espectro da luz ambiente

    // Termo difuso utilizando a lei dos cossenos de Lambert
    vec3 lambert_diffuse_term = Kd * I * max(0, dot(n, l)); // PREENCHA AQUI o termo difuso de Lambert

    // Termo ambiente
    vec3 ambient_term = Ka * Ia; // PREENCHA AQUI o termo ambiente
    vec3 phong_specular_term;
    if ( object_id == CUBE || object_id == PLANE || object_id == TARGET )
    {
        // Blinn-Phong
        vec4 h = normalize(l + v);
        phong_specular_term = Ks * I * pow(max(0, dot(n, h)), q);
    }
    else
    {
        // Termo especular utilizando o modelo de iluminação de Phong
        phong_specular_term  = Ks * I * pow(max(0, dot(r, v)), q); // PREENCH AQUI o termo especular de Phong
    }

    gouraud_shading = lambert_diffuse_term + ambient_term + phong_specular_term;

    if ( object_id == SPHERE )
    {
        color.rgb = KdSphere * gouraud_shading;
    }
        // Cor final do fragmento calculada com uma combinação dos termos difuso,
        // especular, e ambiente. Veja slide 129 do documento Aula_17_e_18_Modelos_de_Iluminacao.pdf.
        color.rgb = lambert_diffuse_term + ambient_term + phong_specular_term;

        // Cor final com correção gamma, considerando monitor sRGB.
        // Veja https://en.wikipedia.org/w/index.php?title=Gamma_correction&oldid=751281772#Windows.2C_Mac.2C_sRGB_and_TV.2Fvideo_standard_gammas
        color.rgb = pow(color.rgb, vec3(1.0,1.0,1.0)/2.2);

}

