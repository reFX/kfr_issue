#include "MainComponent.h"
#include <kfr/capi.h>

#include "Data.cpp"

int getOrder (uint32_t v)
{
	int r = 0;

	while (v >>= 1)
		r++;

	return r;
}

//==============================================================================
MainComponent::MainComponent()
{
	setSize (600, 400);

	std::vector<uint8_t> fftTempBuffer;

	for (const auto& d : all)
	{
		auto sz = int (d.size());
		auto order = getOrder (d.size());

		auto plan = kfr_dft_real_create_plan_f32 (size_t(1) << order, KFR_DFT_PACK_FORMAT::Perm);
		fftTempBuffer.resize (kfr_dft_real_get_temp_size_f32 (plan));

		printf ("size: %d\n", sz);

		std::vector<float> output;
		output.resize (sz);

		kfr_dft_real_execute_inverse_f32 (plan, output.data(), d.data(), fftTempBuffer.data());

		kfr_dft_real_delete_plan_f32 (plan);

		outputs.push_back (output);
	}
}
MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

	//auto h = getHeight() / float (outputs.size());

	auto rc = getLocalBounds().toFloat();

	for (auto& o : outputs)
	{
		auto r = rc; //.removeFromTop (h);

		auto min = *std::min_element (o.begin(), o.end());
		auto max = *std::min_element (o.begin(), o.end());

		max = std::max (std::abs (min), std::abs (max));

		juce::Path p;

		int i = 0;
		for (auto v : o)
		{
			auto x = float (i) / std::size (o) * r.getWidth();
			auto y = v / max * r.getHeight() / 2 + r.getCentreY();

			if (i == 0)
				p.startNewSubPath (x, y);
			else
				p.lineTo (x, y);

			i++;
		}

		auto x = r.getWidth();
		auto y = o[0] / max * r.getHeight() / 2 + r.getCentreY();
		p.lineTo (x, y);

		g.setColour (juce::Colours::white);
		g.strokePath (p, juce::PathStrokeType(1));
	}
}

void MainComponent::resized()
{
}
