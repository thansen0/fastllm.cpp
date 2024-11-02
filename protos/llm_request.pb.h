// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: llm_request.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_llm_5frequest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_llm_5frequest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_llm_5frequest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_llm_5frequest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_llm_5frequest_2eproto;
namespace llm_request {
class LLMInference;
class LLMInferenceDefaultTypeInternal;
extern LLMInferenceDefaultTypeInternal _LLMInference_default_instance_;
class LLMInit;
class LLMInitDefaultTypeInternal;
extern LLMInitDefaultTypeInternal _LLMInit_default_instance_;
}  // namespace llm_request
PROTOBUF_NAMESPACE_OPEN
template<> ::llm_request::LLMInference* Arena::CreateMaybeMessage<::llm_request::LLMInference>(Arena*);
template<> ::llm_request::LLMInit* Arena::CreateMaybeMessage<::llm_request::LLMInit>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace llm_request {

// ===================================================================

class LLMInit PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:llm_request.LLMInit) */ {
 public:
  inline LLMInit() : LLMInit(nullptr) {};
  virtual ~LLMInit();

  LLMInit(const LLMInit& from);
  LLMInit(LLMInit&& from) noexcept
    : LLMInit() {
    *this = ::std::move(from);
  }

  inline LLMInit& operator=(const LLMInit& from) {
    CopyFrom(from);
    return *this;
  }
  inline LLMInit& operator=(LLMInit&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const LLMInit& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LLMInit* internal_default_instance() {
    return reinterpret_cast<const LLMInit*>(
               &_LLMInit_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LLMInit& a, LLMInit& b) {
    a.Swap(&b);
  }
  inline void Swap(LLMInit* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LLMInit* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LLMInit* New() const final {
    return CreateMaybeMessage<LLMInit>(nullptr);
  }

  LLMInit* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LLMInit>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const LLMInit& from);
  void MergeFrom(const LLMInit& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LLMInit* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "llm_request.LLMInit";
  }
  protected:
  explicit LLMInit(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_llm_5frequest_2eproto);
    return ::descriptor_table_llm_5frequest_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kApiKeyFieldNumber = 1,
    kPromptFieldNumber = 2,
  };
  // string apiKey = 1;
  void clear_apikey();
  const std::string& apikey() const;
  void set_apikey(const std::string& value);
  void set_apikey(std::string&& value);
  void set_apikey(const char* value);
  void set_apikey(const char* value, size_t size);
  std::string* mutable_apikey();
  std::string* release_apikey();
  void set_allocated_apikey(std::string* apikey);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_apikey();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_apikey(
      std::string* apikey);
  private:
  const std::string& _internal_apikey() const;
  void _internal_set_apikey(const std::string& value);
  std::string* _internal_mutable_apikey();
  public:

  // string prompt = 2;
  void clear_prompt();
  const std::string& prompt() const;
  void set_prompt(const std::string& value);
  void set_prompt(std::string&& value);
  void set_prompt(const char* value);
  void set_prompt(const char* value, size_t size);
  std::string* mutable_prompt();
  std::string* release_prompt();
  void set_allocated_prompt(std::string* prompt);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_prompt();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_prompt(
      std::string* prompt);
  private:
  const std::string& _internal_prompt() const;
  void _internal_set_prompt(const std::string& value);
  std::string* _internal_mutable_prompt();
  public:

  // @@protoc_insertion_point(class_scope:llm_request.LLMInit)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr apikey_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr prompt_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_llm_5frequest_2eproto;
};
// -------------------------------------------------------------------

class LLMInference PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:llm_request.LLMInference) */ {
 public:
  inline LLMInference() : LLMInference(nullptr) {};
  virtual ~LLMInference();

  LLMInference(const LLMInference& from);
  LLMInference(LLMInference&& from) noexcept
    : LLMInference() {
    *this = ::std::move(from);
  }

  inline LLMInference& operator=(const LLMInference& from) {
    CopyFrom(from);
    return *this;
  }
  inline LLMInference& operator=(LLMInference&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const LLMInference& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LLMInference* internal_default_instance() {
    return reinterpret_cast<const LLMInference*>(
               &_LLMInference_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(LLMInference& a, LLMInference& b) {
    a.Swap(&b);
  }
  inline void Swap(LLMInference* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(LLMInference* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline LLMInference* New() const final {
    return CreateMaybeMessage<LLMInference>(nullptr);
  }

  LLMInference* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<LLMInference>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const LLMInference& from);
  void MergeFrom(const LLMInference& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(LLMInference* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "llm_request.LLMInference";
  }
  protected:
  explicit LLMInference(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_llm_5frequest_2eproto);
    return ::descriptor_table_llm_5frequest_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kAnswerFieldNumber = 1,
  };
  // string answer = 1;
  void clear_answer();
  const std::string& answer() const;
  void set_answer(const std::string& value);
  void set_answer(std::string&& value);
  void set_answer(const char* value);
  void set_answer(const char* value, size_t size);
  std::string* mutable_answer();
  std::string* release_answer();
  void set_allocated_answer(std::string* answer);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_answer();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_answer(
      std::string* answer);
  private:
  const std::string& _internal_answer() const;
  void _internal_set_answer(const std::string& value);
  std::string* _internal_mutable_answer();
  public:

  // @@protoc_insertion_point(class_scope:llm_request.LLMInference)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr answer_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_llm_5frequest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LLMInit

// string apiKey = 1;
inline void LLMInit::clear_apikey() {
  apikey_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& LLMInit::apikey() const {
  // @@protoc_insertion_point(field_get:llm_request.LLMInit.apiKey)
  return _internal_apikey();
}
inline void LLMInit::set_apikey(const std::string& value) {
  _internal_set_apikey(value);
  // @@protoc_insertion_point(field_set:llm_request.LLMInit.apiKey)
}
inline std::string* LLMInit::mutable_apikey() {
  // @@protoc_insertion_point(field_mutable:llm_request.LLMInit.apiKey)
  return _internal_mutable_apikey();
}
inline const std::string& LLMInit::_internal_apikey() const {
  return apikey_.Get();
}
inline void LLMInit::_internal_set_apikey(const std::string& value) {
  
  apikey_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void LLMInit::set_apikey(std::string&& value) {
  
  apikey_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:llm_request.LLMInit.apiKey)
}
inline void LLMInit::set_apikey(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  apikey_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:llm_request.LLMInit.apiKey)
}
inline void LLMInit::set_apikey(const char* value,
    size_t size) {
  
  apikey_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:llm_request.LLMInit.apiKey)
}
inline std::string* LLMInit::_internal_mutable_apikey() {
  
  return apikey_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* LLMInit::release_apikey() {
  // @@protoc_insertion_point(field_release:llm_request.LLMInit.apiKey)
  return apikey_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void LLMInit::set_allocated_apikey(std::string* apikey) {
  if (apikey != nullptr) {
    
  } else {
    
  }
  apikey_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), apikey,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:llm_request.LLMInit.apiKey)
}
inline std::string* LLMInit::unsafe_arena_release_apikey() {
  // @@protoc_insertion_point(field_unsafe_arena_release:llm_request.LLMInit.apiKey)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return apikey_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void LLMInit::unsafe_arena_set_allocated_apikey(
    std::string* apikey) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (apikey != nullptr) {
    
  } else {
    
  }
  apikey_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      apikey, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:llm_request.LLMInit.apiKey)
}

// string prompt = 2;
inline void LLMInit::clear_prompt() {
  prompt_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& LLMInit::prompt() const {
  // @@protoc_insertion_point(field_get:llm_request.LLMInit.prompt)
  return _internal_prompt();
}
inline void LLMInit::set_prompt(const std::string& value) {
  _internal_set_prompt(value);
  // @@protoc_insertion_point(field_set:llm_request.LLMInit.prompt)
}
inline std::string* LLMInit::mutable_prompt() {
  // @@protoc_insertion_point(field_mutable:llm_request.LLMInit.prompt)
  return _internal_mutable_prompt();
}
inline const std::string& LLMInit::_internal_prompt() const {
  return prompt_.Get();
}
inline void LLMInit::_internal_set_prompt(const std::string& value) {
  
  prompt_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void LLMInit::set_prompt(std::string&& value) {
  
  prompt_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:llm_request.LLMInit.prompt)
}
inline void LLMInit::set_prompt(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  prompt_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:llm_request.LLMInit.prompt)
}
inline void LLMInit::set_prompt(const char* value,
    size_t size) {
  
  prompt_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:llm_request.LLMInit.prompt)
}
inline std::string* LLMInit::_internal_mutable_prompt() {
  
  return prompt_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* LLMInit::release_prompt() {
  // @@protoc_insertion_point(field_release:llm_request.LLMInit.prompt)
  return prompt_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void LLMInit::set_allocated_prompt(std::string* prompt) {
  if (prompt != nullptr) {
    
  } else {
    
  }
  prompt_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), prompt,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:llm_request.LLMInit.prompt)
}
inline std::string* LLMInit::unsafe_arena_release_prompt() {
  // @@protoc_insertion_point(field_unsafe_arena_release:llm_request.LLMInit.prompt)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return prompt_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void LLMInit::unsafe_arena_set_allocated_prompt(
    std::string* prompt) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (prompt != nullptr) {
    
  } else {
    
  }
  prompt_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      prompt, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:llm_request.LLMInit.prompt)
}

// -------------------------------------------------------------------

// LLMInference

// string answer = 1;
inline void LLMInference::clear_answer() {
  answer_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& LLMInference::answer() const {
  // @@protoc_insertion_point(field_get:llm_request.LLMInference.answer)
  return _internal_answer();
}
inline void LLMInference::set_answer(const std::string& value) {
  _internal_set_answer(value);
  // @@protoc_insertion_point(field_set:llm_request.LLMInference.answer)
}
inline std::string* LLMInference::mutable_answer() {
  // @@protoc_insertion_point(field_mutable:llm_request.LLMInference.answer)
  return _internal_mutable_answer();
}
inline const std::string& LLMInference::_internal_answer() const {
  return answer_.Get();
}
inline void LLMInference::_internal_set_answer(const std::string& value) {
  
  answer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void LLMInference::set_answer(std::string&& value) {
  
  answer_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:llm_request.LLMInference.answer)
}
inline void LLMInference::set_answer(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  answer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:llm_request.LLMInference.answer)
}
inline void LLMInference::set_answer(const char* value,
    size_t size) {
  
  answer_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:llm_request.LLMInference.answer)
}
inline std::string* LLMInference::_internal_mutable_answer() {
  
  return answer_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* LLMInference::release_answer() {
  // @@protoc_insertion_point(field_release:llm_request.LLMInference.answer)
  return answer_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void LLMInference::set_allocated_answer(std::string* answer) {
  if (answer != nullptr) {
    
  } else {
    
  }
  answer_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), answer,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:llm_request.LLMInference.answer)
}
inline std::string* LLMInference::unsafe_arena_release_answer() {
  // @@protoc_insertion_point(field_unsafe_arena_release:llm_request.LLMInference.answer)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return answer_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void LLMInference::unsafe_arena_set_allocated_answer(
    std::string* answer) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (answer != nullptr) {
    
  } else {
    
  }
  answer_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      answer, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:llm_request.LLMInference.answer)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace llm_request

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_llm_5frequest_2eproto
