// CS148 Summer 2016 Homework 3 - Shaders

#version 330 core
out vec4 color;

in vec3 FragPos;  
in vec3 Normal;  
  
uniform vec3 lightPos; 
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    //combine ambiant light, diffuse light, and specular light
    //adjust w/ attenuation factor
    //assume rgb values are already gamma corrected
    
    float ambientStrength = 0.15f;
    vec3 ambient = ambientStrength * objectColor * lightColor;
    
    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize(lightPos - FragPos);
    float diffuseCoeff = max( dot(norm, lightDirection), 0.0);
    vec3 diffuse = diffuseCoeff * objectColor * lightColor;
    
    float specularStrength = 0.5f;
    vec3 viewDirection = normalize(viewPos - FragPos);
    vec3 reflectDirection = reflect(-lightDirection, norm);
    float specularCoeff = pow(max(dot(viewDirection, reflectDirection), 0.0), 64);
    vec3 specular = specularStrength * specularCoeff * objectColor * lightColor;
    
    float attenuation = 1.0 / (1.0 + .5 * pow(1.0, 2));
    
    vec3 phong = ambient + attenuation * (diffuse + specular);
    color = vec4(phong, 1.0f);
}
