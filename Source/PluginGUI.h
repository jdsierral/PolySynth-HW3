/*
  ==============================================================================

    PluginGUI.h
    Created: 27 Oct 2016 5:04:52am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef PLUGINGUI_H_INCLUDED
#define PLUGINGUI_H_INCLUDED


class PolySynthLookAndFeel		: public LookAndFeel_V3
{
public:
	
	PolySynthLookAndFeel() {
		Colour myColor = Colour(0xFFDDDDDD);
		setColour(Slider::rotarySliderFillColourId, myColor);
		setColour(Slider::rotarySliderOutlineColourId, Colour(0xFF00DCFF));
	}

	void drawButtonBackground (Graphics& g, Button& button, const Colour& backgroundColour,
							   bool isMouseOverButton, bool isButtonDown) override
	{
		Colour baseColour (backgroundColour.withMultipliedSaturation (button.hasKeyboardFocus (true) ? 1.3f : 0.9f)
						   .withMultipliedAlpha (button.isEnabled() ? 0.9f : 0.5f));
		
		if (isButtonDown || isMouseOverButton)
			baseColour = baseColour.contrasting (isButtonDown ? 0.2f : 0.1f);
			
			const bool flatOnLeft   = button.isConnectedOnLeft();
			const bool flatOnRight  = button.isConnectedOnRight();
			const bool flatOnTop    = button.isConnectedOnTop();
			const bool flatOnBottom = button.isConnectedOnBottom();
			
			const float width  = button.getWidth() - 1.0f;
		const float height = button.getHeight() - 1.0f;
		
		if (width > 0 && height > 0)
		{
			const float cornerSize = jmin (15.0f, jmin (width, height) * 0.45f);
			const float lineThickness = cornerSize * 0.1f;
			const float halfThickness = lineThickness * 0.5f;
			
			Path outline;
			outline.addRoundedRectangle (0.5f + halfThickness, 0.5f + halfThickness, width - lineThickness, height - lineThickness,
										 cornerSize, cornerSize,
										 ! (flatOnLeft  || flatOnTop),
										 ! (flatOnRight || flatOnTop),
										 ! (flatOnLeft  || flatOnBottom),
										 ! (flatOnRight || flatOnBottom));
			
			const Colour outlineColour (button.findColour (button.getToggleState() ? TextButton::textColourOnId
														   : TextButton::textColourOffId));
			
			g.setColour (baseColour);
			g.fillPath (outline);
			
			if (! button.getToggleState())
			{
				g.setColour (outlineColour);
				g.strokePath (outline, PathStrokeType (lineThickness));
			}
		}
	}
	
	void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
						   float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
	{
		const float diameter = jmin (width, height) - 4.0f;
		const float radius = (diameter / 2.0f) * std::cos (float_Pi / 4.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius;
		const float ry = centreY - radius;
		const float rw = radius * 2.0f;
		const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
		
		const Colour baseColour (slider.isEnabled() ?
								 slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 0.8f : 1.0f)
								 : Colour (0x80808080));
		
		Rectangle<float> r (rx, ry, rw, rw);
		AffineTransform t (AffineTransform::rotation (angle, r.getCentreX(), r.getCentreY()));
		
		float	x1 = r.getTopLeft().getX(),
				y1 = r.getTopLeft().getY(),
				x2 = r.getBottomLeft().getX(),
				y2 = r.getBottomLeft().getY();
		t.transformPoints (x1, y1, x2, y2);
		
		g.setGradientFill (ColourGradient (baseColour.darker (0.6f), x1, y1,
										   baseColour.darker (0.9f), x2, y2,
										   false));
		Path knobShadow;
		knobShadow.addEllipse(r);
		g.fillPath (knobShadow, t.translated(0, 1));
		
		g.setGradientFill (ColourGradient (baseColour, x1, y1,
										   baseColour.darker (0.2f), x2, y2,
										   false));
		Path knob;
		knob.addEllipse (r);
		g.fillPath (knob, t);

		Rectangle<float> r2 (r * 0.1f);
		float borderScale = 1.2;
		Path needleShadow;
		needleShadow.addEllipse(r2.withPosition(Point<float> (r.getCentreX() - ((r2.getWidth())), r.getY() * borderScale)));
		g.setColour ((slider.findColour (Slider::rotarySliderOutlineColourId)).darker(0.9f));
		g.fillPath (needleShadow, (AffineTransform::rotation (angle, r.getCentreX(), r.getCentreY())).translated(0, -1));
		
		Path needle;
		needle.addEllipse (r2.withPosition (Point<float> (r.getCentreX() - ((r2.getWidth())), r.getY() * borderScale)));
		g.setColour (slider.findColour (Slider::rotarySliderOutlineColourId));
		g.fillPath (needle, AffineTransform::rotation (angle, r.getCentreX(), r.getCentreY()));
		
		
		g.setGradientFill (ColourGradient (Colour(0x00000000), r.getTopLeft().getX(), r.getTopLeft().getY(),
										   Colour(0x64646464), r.getBottomLeft().getX(), r.getBottomLeft().getY(),
										   false));
		Path knobOverlay;
		knobOverlay.addEllipse (r);
		g.fillPath (knobOverlay);
	}
	
	
//	void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
//						   float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override
//	{
//		const float radius = jmin (width / 2, height / 2) - 2.0f;
//		const float centreX = x + width * 0.5f;
//		const float centreY = y + height * 0.5f;
//		const float rx = centreX - radius;
//		const float ry = centreY - radius;
//		const float rw = radius * 2.0f;
//		const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
//		const bool isMouseOver = slider.isMouseOverOrDragging() && slider.isEnabled();
//		
//		if (slider.isEnabled())
//			g.setColour (slider.findColour (Slider::rotarySliderFillColourId).withAlpha (isMouseOver ? 1.0f : 0.7f));
//			else
//				g.setColour (Colour (0x80808080));
//				
//			{
//				Path filledArc;
//				filledArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, angle, 0.0);
//				g.fillPath (filledArc);
//			}
//		
//		{
//			const float lineThickness = jmin (15.0f, jmin (width, height) * 0.45f) * 0.1f;
//			Path outlineArc;
//			outlineArc.addPieSegment (rx, ry, rw, rw, rotaryStartAngle, rotaryEndAngle, 0.0);
//			g.strokePath (outlineArc, PathStrokeType (lineThickness));
//		}
//	}
};




#endif  // PLUGINGUI_H_INCLUDED
