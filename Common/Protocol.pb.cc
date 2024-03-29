// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#include "Protocol.pb.h"

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

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace Protocol {
PROTOBUF_CONSTEXPR Login::Login(
    ::_pbi::ConstantInitialized)
  : user_name_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , allow_(false){}
struct LoginDefaultTypeInternal {
  PROTOBUF_CONSTEXPR LoginDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~LoginDefaultTypeInternal() {}
  union {
    Login _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 LoginDefaultTypeInternal _Login_default_instance_;
PROTOBUF_CONSTEXPR BuffData::BuffData(
    ::_pbi::ConstantInitialized)
  : send_time_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , send_user_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , recv_user_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{})
  , message_all_(&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}){}
struct BuffDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BuffDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~BuffDataDefaultTypeInternal() {}
  union {
    BuffData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BuffDataDefaultTypeInternal _BuffData_default_instance_;
}  // namespace Protocol
static ::_pb::Metadata file_level_metadata_Protocol_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_Protocol_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_Protocol_2eproto = nullptr;

const uint32_t TableStruct_Protocol_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::Login, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::Login, allow_),
  PROTOBUF_FIELD_OFFSET(::Protocol::Login, user_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, send_time_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, send_user_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, recv_user_),
  PROTOBUF_FIELD_OFFSET(::Protocol::BuffData, message_all_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Protocol::Login)},
  { 8, -1, -1, sizeof(::Protocol::BuffData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::Protocol::_Login_default_instance_._instance,
  &::Protocol::_BuffData_default_instance_._instance,
};

const char descriptor_table_protodef_Protocol_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016Protocol.proto\022\010Protocol\")\n\005Login\022\r\n\005a"
  "llow\030\001 \001(\010\022\021\n\tuser_name\030\002 \001(\t\"X\n\010BuffDat"
  "a\022\021\n\tsend_time\030\001 \001(\t\022\021\n\tsend_user\030\002 \001(\t\022"
  "\021\n\trecv_user\030\003 \001(\t\022\023\n\013message_all\030\004 \001(\tb"
  "\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_Protocol_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_Protocol_2eproto = {
    false, false, 167, descriptor_table_protodef_Protocol_2eproto,
    "Protocol.proto",
    &descriptor_table_Protocol_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_Protocol_2eproto::offsets,
    file_level_metadata_Protocol_2eproto, file_level_enum_descriptors_Protocol_2eproto,
    file_level_service_descriptors_Protocol_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_Protocol_2eproto_getter() {
  return &descriptor_table_Protocol_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_Protocol_2eproto(&descriptor_table_Protocol_2eproto);
namespace Protocol {

// ===================================================================

class Login::_Internal {
 public:
};

Login::Login(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Protocol.Login)
}
Login::Login(const Login& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  user_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    user_name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_user_name().empty()) {
    user_name_.Set(from._internal_user_name(), 
      GetArenaForAllocation());
  }
  allow_ = from.allow_;
  // @@protoc_insertion_point(copy_constructor:Protocol.Login)
}

inline void Login::SharedCtor() {
user_name_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  user_name_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
allow_ = false;
}

Login::~Login() {
  // @@protoc_insertion_point(destructor:Protocol.Login)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Login::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  user_name_.Destroy();
}

void Login::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void Login::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.Login)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  user_name_.ClearToEmpty();
  allow_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Login::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool allow = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          allow_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string user_name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_user_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.Login.user_name"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Login::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.Login)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool allow = 1;
  if (this->_internal_allow() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(1, this->_internal_allow(), target);
  }

  // string user_name = 2;
  if (!this->_internal_user_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_user_name().data(), static_cast<int>(this->_internal_user_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.Login.user_name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_user_name(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.Login)
  return target;
}

size_t Login::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.Login)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_name = 2;
  if (!this->_internal_user_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_user_name());
  }

  // bool allow = 1;
  if (this->_internal_allow() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Login::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    Login::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Login::GetClassData() const { return &_class_data_; }

void Login::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<Login *>(to)->MergeFrom(
      static_cast<const Login &>(from));
}


void Login::MergeFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.Login)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_name().empty()) {
    _internal_set_user_name(from._internal_user_name());
  }
  if (from._internal_allow() != 0) {
    _internal_set_allow(from._internal_allow());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Login::CopyFrom(const Login& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.Login)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Login::IsInitialized() const {
  return true;
}

void Login::InternalSwap(Login* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &user_name_, lhs_arena,
      &other->user_name_, rhs_arena
  );
  swap(allow_, other->allow_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Login::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Protocol_2eproto_getter, &descriptor_table_Protocol_2eproto_once,
      file_level_metadata_Protocol_2eproto[0]);
}

// ===================================================================

class BuffData::_Internal {
 public:
};

BuffData::BuffData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  // @@protoc_insertion_point(arena_constructor:Protocol.BuffData)
}
BuffData::BuffData(const BuffData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  send_time_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    send_time_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_send_time().empty()) {
    send_time_.Set(from._internal_send_time(), 
      GetArenaForAllocation());
  }
  send_user_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    send_user_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_send_user().empty()) {
    send_user_.Set(from._internal_send_user(), 
      GetArenaForAllocation());
  }
  recv_user_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    recv_user_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_recv_user().empty()) {
    recv_user_.Set(from._internal_recv_user(), 
      GetArenaForAllocation());
  }
  message_all_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    message_all_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_message_all().empty()) {
    message_all_.Set(from._internal_message_all(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:Protocol.BuffData)
}

inline void BuffData::SharedCtor() {
send_time_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  send_time_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
send_user_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  send_user_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
recv_user_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  recv_user_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
message_all_.InitDefault();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  message_all_.Set("", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

BuffData::~BuffData() {
  // @@protoc_insertion_point(destructor:Protocol.BuffData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void BuffData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  send_time_.Destroy();
  send_user_.Destroy();
  recv_user_.Destroy();
  message_all_.Destroy();
}

void BuffData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void BuffData::Clear() {
// @@protoc_insertion_point(message_clear_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  send_time_.ClearToEmpty();
  send_user_.ClearToEmpty();
  recv_user_.ClearToEmpty();
  message_all_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BuffData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string send_time = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_send_time();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.BuffData.send_time"));
        } else
          goto handle_unusual;
        continue;
      // string send_user = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_send_user();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.BuffData.send_user"));
        } else
          goto handle_unusual;
        continue;
      // string recv_user = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_recv_user();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.BuffData.recv_user"));
        } else
          goto handle_unusual;
        continue;
      // string message_all = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_message_all();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "Protocol.BuffData.message_all"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* BuffData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Protocol.BuffData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string send_time = 1;
  if (!this->_internal_send_time().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_send_time().data(), static_cast<int>(this->_internal_send_time().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.BuffData.send_time");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_send_time(), target);
  }

  // string send_user = 2;
  if (!this->_internal_send_user().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_send_user().data(), static_cast<int>(this->_internal_send_user().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.BuffData.send_user");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_send_user(), target);
  }

  // string recv_user = 3;
  if (!this->_internal_recv_user().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_recv_user().data(), static_cast<int>(this->_internal_recv_user().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.BuffData.recv_user");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_recv_user(), target);
  }

  // string message_all = 4;
  if (!this->_internal_message_all().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_message_all().data(), static_cast<int>(this->_internal_message_all().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "Protocol.BuffData.message_all");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_message_all(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Protocol.BuffData)
  return target;
}

size_t BuffData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Protocol.BuffData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string send_time = 1;
  if (!this->_internal_send_time().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_send_time());
  }

  // string send_user = 2;
  if (!this->_internal_send_user().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_send_user());
  }

  // string recv_user = 3;
  if (!this->_internal_recv_user().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_recv_user());
  }

  // string message_all = 4;
  if (!this->_internal_message_all().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_message_all());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BuffData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    BuffData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BuffData::GetClassData() const { return &_class_data_; }

void BuffData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<BuffData *>(to)->MergeFrom(
      static_cast<const BuffData &>(from));
}


void BuffData::MergeFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Protocol.BuffData)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_send_time().empty()) {
    _internal_set_send_time(from._internal_send_time());
  }
  if (!from._internal_send_user().empty()) {
    _internal_set_send_user(from._internal_send_user());
  }
  if (!from._internal_recv_user().empty()) {
    _internal_set_recv_user(from._internal_recv_user());
  }
  if (!from._internal_message_all().empty()) {
    _internal_set_message_all(from._internal_message_all());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BuffData::CopyFrom(const BuffData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Protocol.BuffData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BuffData::IsInitialized() const {
  return true;
}

void BuffData::InternalSwap(BuffData* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &send_time_, lhs_arena,
      &other->send_time_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &send_user_, lhs_arena,
      &other->send_user_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &recv_user_, lhs_arena,
      &other->recv_user_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &message_all_, lhs_arena,
      &other->message_all_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata BuffData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_Protocol_2eproto_getter, &descriptor_table_Protocol_2eproto_once,
      file_level_metadata_Protocol_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Protocol::Login*
Arena::CreateMaybeMessage< ::Protocol::Login >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::Login >(arena);
}
template<> PROTOBUF_NOINLINE ::Protocol::BuffData*
Arena::CreateMaybeMessage< ::Protocol::BuffData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Protocol::BuffData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
#include "pch.h"