#pragma once

#include "Kernel\OVR_Math.h"
#include "GlProgram.h"
#include "Input.h"
#include "SceneView.h"
#include "Manga.h"

using namespace OVR;
namespace OvrMangaroll {
	class Mangaroll;

	class MangaCarousel
	{
	public:
		MangaCarousel(Mangaroll *mangaroll);
		~MangaCarousel();

		void OneTimeInit(const char * launchIntent);
		void OneTimeShutdown();
		Matrix4f Frame(const VrFrame & vrFrame);

		Matrix4f GetEyeViewMatrix(const int eye) const;
		Matrix4f GetEyeProjectionMatrix(const int eye, const float fovDegreesX, const float fovDegreesY) const;
		Matrix4f DrawEyeView(const int eye, const float fovDegreesX, const float fovDegreesY, ovrFrameParms & frameParms);
		void SetManga(Manga *manga);
		OvrSceneView Scene;
		Manga *CurrentManga;
		Manga *NextManga;
	private:
		GlProgram *_Prog;
		ovrMatrix4f _CenterEyeViewMatrix;
		Mangaroll *_Mangaroll;
		Vector3f _PrevLookAt;
		float _Angle;
		float _LastPress;
	};



}