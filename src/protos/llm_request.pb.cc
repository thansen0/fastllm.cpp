// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: llm_request.proto

#include "llm_request.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace llm_request {
class LLMInitDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<LLMInit> _instance;
} _LLMInit_default_instance_;
class LLMInferenceDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<LLMInference> _instance;
} _LLMInference_default_instance_;
}  // namespace llm_request
static void InitDefaultsscc_info_LLMInference_llm_5frequest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::llm_request::_LLMInference_default_instance_;
    new (ptr) ::llm_request::LLMInference();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::llm_request::LLMInference::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_LLMInference_llm_5frequest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_LLMInference_llm_5frequest_2eproto}, {}};

static void InitDefaultsscc_info_LLMInit_llm_5frequest_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::llm_request::_LLMInit_default_instance_;
    new (ptr) ::llm_request::LLMInit();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::llm_request::LLMInit::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_LLMInit_llm_5frequest_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_LLMInit_llm_5frequest_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_llm_5frequest_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_llm_5frequest_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_llm_5frequest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_llm_5frequest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::llm_request::LLMInit, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::llm_request::LLMInit, apikey_),
  PROTOBUF_FIELD_OFFSET(::llm_request::LLMInit, prompt_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::llm_request::LLMInference, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::llm_request::LLMInference, answer_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::llm_request::LLMInit)},
  { 7, -1, sizeof(::llm_request::LLMInference)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::llm_request::_LLMInit_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::llm_request::_LLMInference_default_instance_),
};

const char descriptor_table_protodef_llm_5frequest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021llm_request.proto\022\013llm_request\")\n\007LLMI"
  "nit\022\016\n\006apiKey\030\001 \001(\t\022\016\n\006prompt\030\002 \001(\t\"\036\n\014L"
  "LMInference\022\016\n\006answer\030\001 \001(\t2P\n\016AskLLMQue"
  "stion\022>\n\tPromptLLM\022\024.llm_request.LLMInit"
  "\032\031.llm_request.LLMInference\"\000b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_llm_5frequest_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_llm_5frequest_2eproto_sccs[2] = {
  &scc_info_LLMInference_llm_5frequest_2eproto.base,
  &scc_info_LLMInit_llm_5frequest_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_llm_5frequest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_llm_5frequest_2eproto = {
  false, false, descriptor_table_protodef_llm_5frequest_2eproto, "llm_request.proto", 197,
  &descriptor_table_llm_5frequest_2eproto_once, descriptor_table_llm_5frequest_2eproto_sccs, descriptor_table_llm_5frequest_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_llm_5frequest_2eproto::offsets,
  file_level_metadata_llm_5frequest_2eproto, 2, file_level_enum_descriptors_llm_5frequest_2eproto, file_level_service_descriptors_llm_5frequest_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_llm_5frequest_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_llm_5frequest_2eproto)), true);
namespace llm_request {

// ===================================================================

void LLMInit::InitAsDefaultInstance() {
}
class LLMInit::_Internal {
 public:
};

LLMInit::LLMInit(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:llm_request.LLMInit)
}
LLMInit::LLMInit(const LLMInit& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  apikey_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_apikey().empty()) {
    apikey_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_apikey(),
      GetArena());
  }
  prompt_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_prompt().empty()) {
    prompt_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_prompt(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:llm_request.LLMInit)
}

void LLMInit::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_LLMInit_llm_5frequest_2eproto.base);
  apikey_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  prompt_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

LLMInit::~LLMInit() {
  // @@protoc_insertion_point(destructor:llm_request.LLMInit)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LLMInit::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  apikey_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  prompt_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void LLMInit::ArenaDtor(void* object) {
  LLMInit* _this = reinterpret_cast< LLMInit* >(object);
  (void)_this;
}
void LLMInit::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LLMInit::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const LLMInit& LLMInit::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_LLMInit_llm_5frequest_2eproto.base);
  return *internal_default_instance();
}


void LLMInit::Clear() {
// @@protoc_insertion_point(message_clear_start:llm_request.LLMInit)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  apikey_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  prompt_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LLMInit::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string apiKey = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_apikey();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "llm_request.LLMInit.apiKey"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string prompt = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_prompt();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "llm_request.LLMInit.prompt"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* LLMInit::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:llm_request.LLMInit)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string apiKey = 1;
  if (this->apikey().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_apikey().data(), static_cast<int>(this->_internal_apikey().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "llm_request.LLMInit.apiKey");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_apikey(), target);
  }

  // string prompt = 2;
  if (this->prompt().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_prompt().data(), static_cast<int>(this->_internal_prompt().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "llm_request.LLMInit.prompt");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_prompt(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:llm_request.LLMInit)
  return target;
}

size_t LLMInit::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:llm_request.LLMInit)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string apiKey = 1;
  if (this->apikey().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_apikey());
  }

  // string prompt = 2;
  if (this->prompt().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_prompt());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LLMInit::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:llm_request.LLMInit)
  GOOGLE_DCHECK_NE(&from, this);
  const LLMInit* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LLMInit>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:llm_request.LLMInit)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:llm_request.LLMInit)
    MergeFrom(*source);
  }
}

void LLMInit::MergeFrom(const LLMInit& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:llm_request.LLMInit)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.apikey().size() > 0) {
    _internal_set_apikey(from._internal_apikey());
  }
  if (from.prompt().size() > 0) {
    _internal_set_prompt(from._internal_prompt());
  }
}

void LLMInit::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:llm_request.LLMInit)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LLMInit::CopyFrom(const LLMInit& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:llm_request.LLMInit)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LLMInit::IsInitialized() const {
  return true;
}

void LLMInit::InternalSwap(LLMInit* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  apikey_.Swap(&other->apikey_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  prompt_.Swap(&other->prompt_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata LLMInit::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void LLMInference::InitAsDefaultInstance() {
}
class LLMInference::_Internal {
 public:
};

LLMInference::LLMInference(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:llm_request.LLMInference)
}
LLMInference::LLMInference(const LLMInference& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  answer_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_answer().empty()) {
    answer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_answer(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:llm_request.LLMInference)
}

void LLMInference::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_LLMInference_llm_5frequest_2eproto.base);
  answer_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

LLMInference::~LLMInference() {
  // @@protoc_insertion_point(destructor:llm_request.LLMInference)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LLMInference::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  answer_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void LLMInference::ArenaDtor(void* object) {
  LLMInference* _this = reinterpret_cast< LLMInference* >(object);
  (void)_this;
}
void LLMInference::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LLMInference::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const LLMInference& LLMInference::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_LLMInference_llm_5frequest_2eproto.base);
  return *internal_default_instance();
}


void LLMInference::Clear() {
// @@protoc_insertion_point(message_clear_start:llm_request.LLMInference)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  answer_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LLMInference::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string answer = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_answer();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "llm_request.LLMInference.answer"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* LLMInference::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:llm_request.LLMInference)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string answer = 1;
  if (this->answer().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_answer().data(), static_cast<int>(this->_internal_answer().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "llm_request.LLMInference.answer");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_answer(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:llm_request.LLMInference)
  return target;
}

size_t LLMInference::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:llm_request.LLMInference)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string answer = 1;
  if (this->answer().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_answer());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LLMInference::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:llm_request.LLMInference)
  GOOGLE_DCHECK_NE(&from, this);
  const LLMInference* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LLMInference>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:llm_request.LLMInference)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:llm_request.LLMInference)
    MergeFrom(*source);
  }
}

void LLMInference::MergeFrom(const LLMInference& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:llm_request.LLMInference)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.answer().size() > 0) {
    _internal_set_answer(from._internal_answer());
  }
}

void LLMInference::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:llm_request.LLMInference)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LLMInference::CopyFrom(const LLMInference& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:llm_request.LLMInference)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LLMInference::IsInitialized() const {
  return true;
}

void LLMInference::InternalSwap(LLMInference* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  answer_.Swap(&other->answer_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata LLMInference::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace llm_request
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::llm_request::LLMInit* Arena::CreateMaybeMessage< ::llm_request::LLMInit >(Arena* arena) {
  return Arena::CreateMessageInternal< ::llm_request::LLMInit >(arena);
}
template<> PROTOBUF_NOINLINE ::llm_request::LLMInference* Arena::CreateMaybeMessage< ::llm_request::LLMInference >(Arena* arena) {
  return Arena::CreateMessageInternal< ::llm_request::LLMInference >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
