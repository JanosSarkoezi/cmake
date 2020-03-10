#version 330

layout (std140) uniform Matrices {
	mat4 m_pvm;
	mat4 m_viewModel;
	mat3 m_normal;
};

in vec4 position;

void main()
{
	gl_Position = m_pvm * position ;
} 
