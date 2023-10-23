module;

#include <WickedEngine/WickedEngine.h>

export module wicked_engine;

export namespace wi
{
    using wi::Application;
    using wi::RenderPath3D;
    using wi::GPUBVH;
    using wi::EmittedParticleSystem;
    using wi::HairParticleSystem;
    using wi::Ocean;
    using wi::Sprite;
    using wi::SpriteFont;
    using wi::Archive;
    using wi::Color;
    using wi::FadeManager;
    using wi::Resource;
    using wi::SpinLock;
    using wi::Timer;
    using wi::Canvas;

    namespace audio
    {
        using wi::audio::Sound;
        using wi::audio::SoundInstance;
    }

    namespace arguments
    {
        using wi::arguments::Parse;
    }

    namespace ecs
    {
        using wi::ecs::Entity;
        using wi::ecs::INVALID_ENTITY;
    }

    namespace eventhandler
    {
        using wi::eventhandler::EVENT_THREAD_SAFE_POINT;
        using wi::eventhandler::EVENT_RELOAD_SHADERS;
        using wi::eventhandler::EVENT_SET_VSYNC;

        using wi::eventhandler::SetVSync;
    }

    namespace font
    {
        using wi::font::Params;
        using wi::font::Alignment;
    }

    namespace gui
    {
        using wi::gui::Button;
        using wi::gui::CheckBox;
        using wi::gui::ColorPicker;
        using wi::gui::ComboBox;
        using wi::gui::EventArgs;
        using wi::gui::GUI;
        using wi::gui::Label;
        using wi::gui::Slider;
        using wi::gui::TextInputField;
        using wi::gui::TreeList;
        using wi::gui::Widget;
        using wi::gui::Window;
    }

    namespace graphics
    {
        using wi::graphics::Shader;
        using wi::graphics::GPUResource;
        using wi::graphics::GPUBuffer;
        using wi::graphics::Texture;

        // enums
        using wi::graphics::ValidationMode;
        using wi::graphics::AdapterType;
        using wi::graphics::GPUPreference;
        using wi::graphics::ShaderStage;
        using wi::graphics::ShaderFormat;
        using wi::graphics::ShaderModel;
        using wi::graphics::PrimitiveTopology;
        using wi::graphics::ComparisonFunc;
        using wi::graphics::DepthWriteMask;
        using wi::graphics::StencilOp;
        using wi::graphics::Blend;
        using wi::graphics::BlendOp;
        using wi::graphics::FillMode;
        using wi::graphics::CullMode;
        using wi::graphics::InputClassification;
        using wi::graphics::Usage;
        using wi::graphics::TextureAddressMode;
        using wi::graphics::Filter;
        using wi::graphics::SamplerBorderColor;
        using wi::graphics::Format;
        using wi::graphics::GpuQueryType;
        using wi::graphics::IndexBufferFormat;
        using wi::graphics::SubresourceType;
        using wi::graphics::ShadingRate;
        using wi::graphics::PredicationOp;
        using wi::graphics::ImageAspect;
        using wi::graphics::VideoFrameType;
        using wi::graphics::VideoProfile;
        using wi::graphics::ComponentSwizzle;
        using wi::graphics::ColorWrite;
        using wi::graphics::BindFlag;
        using wi::graphics::ResourceMiscFlag;
        using wi::graphics::GraphicsDeviceCapability;
        using wi::graphics::ColorSpace;
        using wi::graphics::RenderPassFlags;

        // Descriptor structs
        using wi::graphics::Viewport;
        using wi::graphics::InputLayout;
        using wi::graphics::ClearValue;
        using wi::graphics::Swizzle;
        using wi::graphics::TextureDesc;
        using wi::graphics::SamplerDesc;
        using wi::graphics::RasterizerState;
        using wi::graphics::DepthStencilState;
        using wi::graphics::BlendState;
        using wi::graphics::GPUBufferDesc;
        using wi::graphics::GPUQueryHeapDesc;
        using wi::graphics::PipelineStateDesc;
        using wi::graphics::GPUBarrier;
        using wi::graphics::SwapChainDesc;
        using wi::graphics::SubresourceData;
        using wi::graphics::Rect;
        using wi::graphics::Box;
        using wi::graphics::SparseTextureProperties;
        using wi::graphics::VideoDesc;

        // Resources
        using wi::graphics::GraphicsDeviceChild;
        using wi::graphics::Sampler;
        using wi::graphics::Shader;
        using wi::graphics::GPUResource;
        using wi::graphics::GPUBuffer;
        using wi::graphics::Texture;
        using wi::graphics::VideoDecoder;
        using wi::graphics::VideoDecodeOperation;
        using wi::graphics::RenderPassImage;
        using wi::graphics::RenderPassInfo;
        using wi::graphics::GPUQueryHeap;
        using wi::graphics::PipelineState;
        using wi::graphics::SwapChain;
        using wi::graphics::RaytracingAccelerationStructureDesc;
        using wi::graphics::RaytracingAccelerationStructure;
        using wi::graphics::ShaderLibrary;
        using wi::graphics::ShaderHitGroup;
        using wi::graphics::RaytracingPipelineStateDesc;
        using wi::graphics::RaytracingPipelineState;
        using wi::graphics::ShaderTable;
        using wi::graphics::DispatchRaysDesc;
        using wi::graphics::SparseResourceCoordinate;
        using wi::graphics::SparseRegionSize;
        using wi::graphics::TileRangeFlags; // enum
        using wi::graphics::SparseUpdateCommand;

        using wi::graphics::IsFormatSRGB;
        using wi::graphics::IsFormatUnorm;
        using wi::graphics::IsFormatBlockCompressed;
        using wi::graphics::IsFormatDepthSupport;
        using wi::graphics::IsFormatStencilSupport;
        using wi::graphics::GetFormatBlockSize;
        using wi::graphics::GetFormatStride;
        using wi::graphics::GetFormatNonSRGB;
        using wi::graphics::GetFormatSRGB;
        using wi::graphics::GetFormatString;
        using wi::graphics::GetIndexBufferFormat;
        using wi::graphics::GetIndexBufferFormatRaw;
        using wi::graphics::GetIndexBufferFormatString;
        using wi::graphics::GetComponentSwizzleChar;
        using wi::graphics::SwizzleString;
        using wi::graphics::GetSwizzleString;
        using wi::graphics::AlignTo;
        using wi::graphics::IsAligned;
        using wi::graphics::GetMipCount;
        using wi::graphics::ComputeTextureMemorySizeInBytes;

        using wi::graphics::CommandList;
        using wi::graphics::DescriptorBindingTable;
        using wi::graphics::QUEUE_TYPE;
        using wi::graphics::GraphicsDevice;
        using wi::graphics::GetDevice;
    }

    namespace image
    {
        using wi::image::Params;
        using wi::image::STENCILMODE;
        using wi::image::STENCILREFMODE;
        using wi::image::SAMPLEMODE;
        using wi::image::QUALITY;

        using wi::image::SetCanvas;
        using wi::image::SetBackground;
        using wi::image::Draw;
        using wi::image::Initialize;
    }

    namespace math
    {
        using wi::math::IDENTITY_MATRIX;
        using wi::math::PI;
        using wi::math::saturate;
        using wi::math::Length;
        using wi::math::Distance;
        using wi::math::DistanceSquared;
        using wi::math::DistanceEstimated;
        using wi::math::ClosestPointOnLine;
        using wi::math::ClosestPointOnLineSegment;
        using wi::math::getVectorHalfWayPoint;
        using wi::math::InverseLerp;
        using wi::math::Lerp;
        using wi::math::Slerp;
        using wi::math::Max;
        using wi::math::Min;
        using wi::math::Clamp;
        using wi::math::SmoothStep;
        using wi::math::Collision2D;
        using wi::math::GetNextPowerOfTwo;
        using wi::math::TriangleArea;
        using wi::math::SphereSurfaceArea;
        using wi::math::SphereVolume;
        using wi::math::GetCubicHermiteSplinePos;
        using wi::math::GetQuadraticBezierPos;
        using wi::math::QuaternionToRollPitchYaw;
        using wi::math::GetClosestPointToLine;
        using wi::math::GetPointSegmentDistance;
        using wi::math::RadiansToDegrees;
        using wi::math::DegreesToRadians;
        using wi::math::GetAngle;
        using wi::math::ConstructTriangleEquilateral;
        using wi::math::GetBarycentric;
        using wi::math::GetHaltonSequence;
        using wi::math::CompressNormal;
        using wi::math::CompressColor;
        using wi::math::Unpack_R11G11B10_FLOAT;
        using wi::math::Pack_R11G11B10_FLOAT;
        using wi::math::Unpack_R9G9B9E5_SHAREDEXP;
        using wi::math::Pack_R9G9B9E5_SHAREDEXP;
        using wi::math::RayTriangleIntersects;
    }

    namespace primitive
    {
        using wi::primitive::AABB;
        using wi::primitive::Capsule;
        using wi::primitive::Frustum;
        using wi::primitive::Hitbox2D;
        using wi::primitive::Plane;
        using wi::primitive::Ray;
        using wi::primitive::Sphere;
    }

    namespace renderer
    {
        using wi::renderer::format_depthbuffer_main;
        using wi::renderer::format_rendertarget_main;
        using wi::renderer::format_idbuffer;
        using wi::renderer::format_rendertarget_shadowmap;
        using wi::renderer::format_depthbuffer_shadowmap;
        using wi::renderer::format_rendertarget_envprobe;
        using wi::renderer::format_depthbuffer_envprobe;
        using wi::renderer::raytracing_inclusion_mask_shadow;
        using wi::renderer::raytracing_inclusion_mask_reflection;

        using wi::renderer::SetShaderSourcePath;
        using wi::renderer::SetToDrawGridHelper;
        using wi::renderer::SetTemporalAAEnabled;
    }

    namespace scene
    {
        using wi::scene::GetScene;
        using wi::scene::GetCamera;
        using wi::scene::TransformComponent;
        using wi::scene::LoadModel;
        using wi::scene::WeatherComponent;
    }

    // Non wicked stuff
    using ::XMFLOAT2;
    using ::XMFLOAT3;
    using ::XMVECTOR;
    using ::XMFLOAT4X4;
    using ::XMVectorSet;
}

//export static const wi::ecs::Entity wi::ecs::INVALID_ENTITY;
