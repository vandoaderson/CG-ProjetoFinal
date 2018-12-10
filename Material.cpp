#include "Material.h"

Material::Material(Vertice *Ka, Vertice *Kd, Vertice *Ks){
    this->Ka = Ka;
    this->Kd = Kd;
    this->Ks = Ks;
}
Material :: Material(){}
void Material::setMaterialOpenGL()
{
    float ambient[3];
    float diffuse[3];
    float specular[3];
    ambient[0] = Ka->x;
    ambient[1] = Ka->y;
    ambient[2] = Ka->z;
    ambient[3] = Ka->w;
    diffuse[0] = Kd->x;
    diffuse[1] = Kd->y;
    diffuse[2] = Kd->z;
    diffuse[3] = Kd->w;
    specular[0] = Ks->x;
    specular[1] = Ks->y;
    specular[2] = Ks->z;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, m*128);
}
void Material::setMaterialOpenGL(int type)
{
    //Material *mat = new Material();
    setMaterial(this,type);
    float ambient[3];
    float diffuse[3];
    float specular[3];
    ambient[0] = Ka->x;
    ambient[1] = Ka->y;
    ambient[2] = Ka->z;
   // ambient[3] = Ka->w;
    diffuse[0] = Kd->x;
    diffuse[1] = Kd->y;
    diffuse[2] = Kd->z;
    //diffuse[3] = Kd->w;
    specular[0] = Ks->x;
    specular[1] = Ks->y;
    specular[2] = Ks->z;
   // specular[3] = Ks->w;
    glMaterialfv(GL_FRONT, GL_AMBIENT,ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialf(GL_FRONT, GL_SHININESS, m*128);
}
void Material::setMaterial(Material *mat, int type)
{
    if (type==0) return;
    switch (type){
    case MATERIAL_GOLD:{
        mat->Ka->x = 0.25;
        mat->Ka->y = 0.20;
        mat->Ka->z = 0.07;


        mat->Ks->x = 0.63;
        mat->Ks->y = 0.65;
        mat->Ks->z = 0.37;

        mat->Kd->x = 0.75;
        mat->Kd->y = 0.61;
        mat->Kd->z = 0.23;

        mat->m = 0.2;
        break;

    }
    case MATERIAL_GOLD_POLIERT:{
        mat->Ka->x = 0.25;
        mat->Ka->y = 0.22;
        mat->Ka->z = 0.06;
        

        mat->Ks->x = 0.80;
        mat->Ks->y = 0.72;
        mat->Ks->z = 0.21;
        

        mat->Kd->x = 0.35;
        mat->Kd->y = 0.31;
        mat->Kd->z = 0.09;
        

        mat->m = 0.078;
        break;

    }
    case MATERIAL_BRONZE:{
        mat->Ka->x = 0.21;
        mat->Ka->y = 0.13;
        mat->Ka->z = 0.05;
        

        mat->Ks->x = 0.39;
        mat->Ks->y = 0.27;
        mat->Ks->z = 0.17;
        

        mat->Kd->x = 0.71;
        mat->Kd->y = 0.43;
        mat->Kd->z = 0.18;
        

        mat->m = 0.2;
        break;

    }
    case MATERIAL_BRONZE_POLIERT:{
        mat->Ka->x = 0.25;
        mat->Ka->y = 0.15;
        mat->Ka->z = 0.06;
        

        mat->Ks->x = 0.40;
        mat->Ks->y = 0.24;
        mat->Ks->z = 0.10;
        

        mat->Kd->x = 0.77;
        mat->Kd->y = 0.46;
        mat->Kd->z = 0.20;
        

        mat->m = 0.6;
        break;

    }
    case MATERIAL_CHROME:{
        mat->Ka->x = 0.25;
        mat->Ka->y = 0.25;
        mat->Ka->z = 0.25;
        

        mat->Ks->x = 0.77;
        mat->Ks->y = 0.77;
        mat->Ks->z = 0.77;
        

        mat->Kd->x = 0.40;
        mat->Kd->y = 0.40;
        mat->Kd->z = 0.40;
        

        mat->m = 0.6;
        break;

    }
    case MATERIAL_COPPER:{
        mat->Ka->x = 0.19;
        mat->Ka->y = 0.07;
        mat->Ka->z = 0.02;
        

        mat->Ks->x = 0.26;
        mat->Ks->y = 0.14;
        mat->Ks->z = 0.09;
        

        mat->Kd->x = 0.70;
        mat->Kd->y = 0.27;
        mat->Kd->z = 0.08;
        

        mat->m = 0.1;
        break;

    }
    case MATERIAL_COPPER_POLIERT:{
        mat->Ka->x = 0.23;
        mat->Ka->y = 0.09;
        mat->Ka->z = 0.03;
        

        mat->Ks->x = 0.58;
        mat->Ks->y = 0.22;
        mat->Ks->z = 0.07;
        

        mat->Kd->x = 0.55;
        mat->Kd->y = 0.21;
        mat->Kd->z = 0.07;
        

        mat->m = 0.4;
        break;

    }
    case MATERIAL_BRASS:{
        mat->Ka->x = 0.33;
        mat->Ka->y = 0.22;
        mat->Ka->z = 0.03;
        

        mat->Ks->x = 0.99;
        mat->Ks->y = 0.94;
        mat->Ks->z = 0.81;
        

        mat->Kd->x = 0.78;
        mat->Kd->y = 0.57;
        mat->Kd->z = 0.11;
        

        mat->m = 0.218;
        break;

    }
    case MATERIAL_SILVER:{
        mat->Ka->x = 0.0;
        mat->Ka->y = 0.0;
        mat->Ka->z = 0.0;
        

        mat->Ks->x = 0.0;
        mat->Ks->y = 0.0;
        mat->Ks->z = 0.0;
        

        mat->Kd->x = 0.51;
        mat->Kd->y = 0.51;
        mat->Kd->z = 0.51;
        

        mat->m = 0.4;
        break;

    }
    case MATERIAL_SILVER_POLIERT:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0;
        mat->Ks->y = 0;
        mat->Ks->z = 0;
        

        mat->Kd->x = 0;
        mat->Kd->y = 0;
        mat->Kd->z = 0;
        

        mat->m = 0.7;
        break;

    }
    case MATERIAL_ZINN:{
        mat->Ka->x = 0.11;
        mat->Ka->y = 0.06;
        mat->Ka->z = 0.11;
        

        mat->Ks->x = 0.33;
        mat->Ks->y = 0.33;
        mat->Ks->z = 0.52;
        

        mat->Kd->x = 0.43;
        mat->Kd->y = 0.47;
        mat->Kd->z = 0.54;
        

        mat->m = 0.076;
        break;

    }
    case MATERIAL_GUMMI:{
        mat->Ka->x = 0.02;
        mat->Ka->y = 0.02;
        mat->Ka->z = 0.02;
        

        mat->Ks->x = 0.40;
        mat->Ks->y = 0.40;
        mat->Ks->z = 0.40;
        

        mat->Kd->x = 0.01;
        mat->Kd->y = 0.01;
        mat->Kd->z = 0.01;
        

        mat->m = 0.0781;
        break;

    }
    case MATERIAL_PLASTIK:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.5;
        mat->Ks->y = 0.5;
        mat->Ks->z = 0.5;
        

        mat->Kd->x = 0.01;
        mat->Kd->y = 0.01;
        mat->Kd->z = 0.01;
        

        mat->m = 0.25;
        break;


    }
    case MATERIAL_EMERALD:{
        mat->Ka->x = 0.0215;
        mat->Ka->y = 0.1745;
        mat->Ka->z = 0.0215;
        

        mat->Ks->x = 0.633;
        mat->Ks->y = 0.727811;
        mat->Ks->z = 0.633;
        

        mat->Kd->x = 0.07568;
        mat->Kd->y = 0.61424;
        mat->Kd->z = 0.07568;
        

        mat->m = 0.6;
        break;

    }
    case MATERIAL_JADE:{
        mat->Ka->x = 0.135;
        mat->Ka->y = 0.2225;
        mat->Ka->z = 0.1575;
        

        mat->Ks->x = 0.31622;
        mat->Ks->y = 0.31622;
        mat->Ks->z = 0.31622;
        

        mat->Kd->x = 0.54;
        mat->Kd->y = 0.89;
        mat->Kd->z = 0.63;
        

        mat->m = 0.1;

        break;

    }
    case MATERIAL_OBSIDIAN:{
        mat->Ka->x = 0.05375;
        mat->Ka->y = 0.05;
        mat->Ka->z = 0.06625;
        

        mat->Ks->x = 0.332741;
        mat->Ks->y = 0.328634;
        mat->Ks->z = 0.346435;
        

        mat->Kd->x = 0.18275;
        mat->Kd->y = 0.17;
        mat->Kd->z = 0.22525;
        

        mat->m = 0.3;
        break;

    }
    case MATERIAL_PEARL:{
        mat->Ka->x = 0.25;
        mat->Ka->y = 0.20725;
        mat->Ka->z = 0.20725;
        

        mat->Ks->x = 0.296648;
        mat->Ks->y = 0.296648;
        mat->Ks->z = 0.296648;
        

        mat->Kd->x = 1.0;
        mat->Kd->y = 0.829;
        mat->Kd->z = 0.829;
        

        mat->m = 0.088;
        break;

    }
    case MATERIAL_RUBY:{
        mat->Ka->x = 0.1745;
        mat->Ka->y = 0.01175;
        mat->Ka->z = 0.01175;
        

        mat->Ks->x = 0.727811;
        mat->Ks->y = 0.626959;
        mat->Ks->z = 0.626959;
        

        mat->Kd->x = 0.61424;
        mat->Kd->y = 0.04136;
        mat->Kd->z = 0.04136;
        

        mat->m = 0.6;
        break;

    }
    case MATERIAL_TURQUOSIE:{
        mat->Ka->x = 0.1;
        mat->Ka->y = 0.18725;
        mat->Ka->z = 0.1745;
        

        mat->Ks->x = 0.297254;
        mat->Ks->y = 0.30829;
        mat->Ks->z = 0.306678;
        

        mat->Kd->x = 0.396;
        mat->Kd->y = 0.74151;
        mat->Kd->z = 0.69102;
        

        mat->m = 0.1;

        break;

    }
    case MATERIAL_BLACK_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0;
        mat->Ks->y = 0;
        mat->Ks->z = 0;
        

        mat->Kd->x = 0.0;
        mat->Kd->y = 0.0;
        mat->Kd->z = 0.0;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_BLACK_RUBBER:{
        mat->Ka->x = 0.0;
        mat->Ka->y = 0.0;
        mat->Ka->z = 0.0;
        

        mat->Ks->x = 0.0;
        mat->Ks->y = 0.0;
        mat->Ks->z = 0.0;
        

        mat->Kd->x = 0.00;
        mat->Kd->y = 0.00;
        mat->Kd->z = 0.00;
        

        mat->m = 0.078125;

        break;

    }
    case MATERIAL_CYAN_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0.1;
        mat->Ka->z = 0.06;
        

        mat->Ks->x = 0.50196078;
        mat->Ks->y = 0.50196078;
        mat->Ks->z = 0.50196078;
        

        mat->Kd->x = 0;
        mat->Kd->y = 0.509803;
        mat->Kd->z = 0.509803;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_CYAN_RUBBER:{
        mat->Ka->x = 0;
        mat->Ka->y = 0.05;
        mat->Ka->z = 0.05;
        

        mat->Ks->x = 0.04;
        mat->Ks->y = 0.7;
        mat->Ks->z = 0.7;
        

        mat->Kd->x = 0.4;
        mat->Kd->y = 0.5;
        mat->Kd->z = 0.5;
        

        mat->m = 0.078125;
        break;

    }
    case MATERIAL_GREEN_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.45;
        mat->Ks->y = 0.55;
        mat->Ks->z = 0.45;
        

        mat->Kd->x = 0.1;
        mat->Kd->y = 0.35;
        mat->Kd->z = 0.1;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_GREEN_RUBER:{
        mat->Ka->x = 0;
        mat->Ka->y = 0.05;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.04;
        mat->Ks->y = 0.7;
        mat->Ks->z = 0.04;
        

        mat->Kd->x = 0.4;
        mat->Kd->y = 0.5;
        mat->Kd->z = 0.4;
        

        mat->m = 0.078125;
        break;

    }
    case MATERIAL_RED_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.7;
        mat->Ks->y = 0.6;
        mat->Ks->z = 0.6;
        

        mat->Kd->x = 0.5;
        mat->Kd->y = 0;
        mat->Kd->z = 0;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_RED_RUBBER:{
        mat->Ka->x = 0.05;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.7;
        mat->Ks->y = 0.04;
        mat->Ks->z = 0.04;
        

        mat->Kd->x = 0.5;
        mat->Kd->y = 0.4;
        mat->Kd->z = 0.4;
        

        mat->m = 0.078125;
        break;

    }
    case MATERIAL_WHITE_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.7;
        mat->Ks->y = 0.7;
        mat->Ks->z = 0.7;
        

        mat->Kd->x = 0.55;
        mat->Kd->y = 0.55;
        mat->Kd->z = 0.55;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_WHITE_RUBBER:{
        mat->Ka->x = 0.05;
        mat->Ka->y = 0.05;
        mat->Ka->z = 0.05;
        

        mat->Ks->x = 0.7;
        mat->Ks->y = 0.7;
        mat->Ks->z = 0.7;
        

        mat->Kd->x = 0.5;
        mat->Kd->y = 0.5;
        mat->Kd->z = 0.5;
        

        mat->m = 0.078125;
        break;

    }
    case MATERIAL_YELLOW_PLASTIC:{
        mat->Ka->x = 0;
        mat->Ka->y = 0;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.6;
        mat->Ks->y = 0.6;
        mat->Ks->z = 0.5;
        

        mat->Kd->x = 0.5;
        mat->Kd->y = 0.5;
        mat->Kd->z = 0;
        

        mat->m = 0.25;
        break;

    }
    case MATERIAL_YELLOW_RUBBER:{
        mat->Ka->x = 0.05;
        mat->Ka->y = 0.05;
        mat->Ka->z = 0;
        

        mat->Ks->x = 0.7;
        mat->Ks->y = 0.7;
        mat->Ks->z = 0.04;
        

        mat->Kd->x = 0.5;
        mat->Kd->y = 0.5;
        mat->Kd->z = 0.4;
        

        mat->m = 0.078125;
        break;

    }

 }

}
