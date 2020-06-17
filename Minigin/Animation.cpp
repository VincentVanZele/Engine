#include "MiniginPCH.h"
#include "Animation.h"
#include "Texture2D.h"
#include "Renderer.h"

proxy::Animation::Animation(std::shared_ptr<Texture2D> tex, const std::string& name, int nbrFrames)
	: m_pTexture2D{ tex }
	, m_Name{ name }
	, m_nbrFrames{ nbrFrames }, m_currFrame{ 0 }
{
}

void proxy::Animation::Update(float& deltaT)
{
	if (m_FrameDeltatime < 0)
	{
		return;
	}
	else if (m_FrameDeltatime <= deltaT)
	{
		deltaT -= m_FrameDeltatime;
		m_currFrame = (m_currFrame + 1) % m_nbrFrames;

		if (m_currFrame == 0 && !m_Loop)
		{
			m_currFrame = m_nbrFrames - 1;
		}
	}
}

void proxy::Animation::Draw() const
{
	Float4 dest{}, src{};
	float col = (float) (m_pTexture2D->GetTextWidth() / m_nbrFrames);
	float row = (float)m_pTexture2D->GetTextHeight();

	dest = Float4{
		dest._x = m_Pos._x - (col / 2),
		dest._y = m_Pos._y - (dest._w / 2),
		dest._z = col,
		dest._w = row
	};
	
	src = Float4{
		src._x = dest._z * m_currFrame,
		src._y = 0,
		src._z = dest._z,
		src._w = dest._w
	};

	Renderer::GetInstance().RenderTexture(*m_pTexture2D, dest, src);
}

void proxy::Animation::SetFrameDeltatime(float deltaTime)
{
	m_FrameDeltatime = deltaTime;
}

void proxy::Animation::SetName(const std::string& name)
{
	m_Name = name;
}

std::string proxy::Animation::GetName() const
{
	return m_Name;
}

bool proxy::Animation::CheckName(const std::string& name)
{
	return (m_Name.compare(name) == 0);
}

void proxy::Animation::SetNbrOfFrames(int nbrFrames)
{
	m_nbrFrames = nbrFrames;
}

int proxy::Animation::GetNbrOfFrames() const
{
	return m_nbrFrames;
}

void proxy::Animation::SetCurrFrame(int currFrame)
{
	m_currFrame = currFrame;
}

int proxy::Animation::GetCurrFrame() const
{
	return m_currFrame;
}

void proxy::Animation::SetPos(Float2 pos)
{
	m_Pos = pos;
}

proxy::Float2 proxy::Animation::GetPos() const
{
	return m_Pos;
}

void proxy::Animation::SetLoop(bool loop)
{
	m_Loop = loop;
}

bool proxy::Animation::GetLoop() const
{
	return m_Loop;
}

void proxy::Animation::SetTexture(std::shared_ptr<Texture2D> tex)
{
	m_pTexture2D = tex;
}

proxy::Texture2D& proxy::Animation::GetTexture() const
{
	return *m_pTexture2D;
}

void proxy::Animation::SetFrame(int frame)
{
	m_currFrame = frame;
}

