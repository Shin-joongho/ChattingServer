// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Protocol_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Protocol_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Protocol_2eproto;
namespace Protocol {
class BuffData;
struct BuffDataDefaultTypeInternal;
extern BuffDataDefaultTypeInternal _BuffData_default_instance_;
class Login;
struct LoginDefaultTypeInternal;
extern LoginDefaultTypeInternal _Login_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::BuffData* Arena::CreateMaybeMessage<::Protocol::BuffData>(Arena*);
template<> ::Protocol::Login* Arena::CreateMaybeMessage<::Protocol::Login>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class Login final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.Login) */ {
 public:
  inline Login() : Login(nullptr) {}
  ~Login() override;
  explicit PROTOBUF_CONSTEXPR Login(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Login(const Login& from);
  Login(Login&& from) noexcept
    : Login() {
    *this = ::std::move(from);
  }

  inline Login& operator=(const Login& from) {
    CopyFrom(from);
    return *this;
  }
  inline Login& operator=(Login&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Login& default_instance() {
    return *internal_default_instance();
  }
  static inline const Login* internal_default_instance() {
    return reinterpret_cast<const Login*>(
               &_Login_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Login& a, Login& b) {
    a.Swap(&b);
  }
  inline void Swap(Login* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Login* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Login* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Login>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Login& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Login& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Login* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.Login";
  }
  protected:
  explicit Login(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kUserNameFieldNumber = 2,
    kAllowFieldNumber = 1,
  };
  // string user_name = 2;
  void clear_user_name();
  const std::string& user_name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_user_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_user_name();
  PROTOBUF_NODISCARD std::string* release_user_name();
  void set_allocated_user_name(std::string* user_name);
  private:
  const std::string& _internal_user_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_user_name(const std::string& value);
  std::string* _internal_mutable_user_name();
  public:

  // bool allow = 1;
  void clear_allow();
  bool allow() const;
  void set_allow(bool value);
  private:
  bool _internal_allow() const;
  void _internal_set_allow(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.Login)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr user_name_;
  bool allow_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class BuffData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.BuffData) */ {
 public:
  inline BuffData() : BuffData(nullptr) {}
  ~BuffData() override;
  explicit PROTOBUF_CONSTEXPR BuffData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  BuffData(const BuffData& from);
  BuffData(BuffData&& from) noexcept
    : BuffData() {
    *this = ::std::move(from);
  }

  inline BuffData& operator=(const BuffData& from) {
    CopyFrom(from);
    return *this;
  }
  inline BuffData& operator=(BuffData&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const BuffData& default_instance() {
    return *internal_default_instance();
  }
  static inline const BuffData* internal_default_instance() {
    return reinterpret_cast<const BuffData*>(
               &_BuffData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(BuffData& a, BuffData& b) {
    a.Swap(&b);
  }
  inline void Swap(BuffData* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(BuffData* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  BuffData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<BuffData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const BuffData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const BuffData& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BuffData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.BuffData";
  }
  protected:
  explicit BuffData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSendTimeFieldNumber = 1,
    kSendUserFieldNumber = 2,
    kRecvUserFieldNumber = 3,
    kMessageAllFieldNumber = 4,
  };
  // string send_time = 1;
  void clear_send_time();
  const std::string& send_time() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_send_time(ArgT0&& arg0, ArgT... args);
  std::string* mutable_send_time();
  PROTOBUF_NODISCARD std::string* release_send_time();
  void set_allocated_send_time(std::string* send_time);
  private:
  const std::string& _internal_send_time() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_send_time(const std::string& value);
  std::string* _internal_mutable_send_time();
  public:

  // string send_user = 2;
  void clear_send_user();
  const std::string& send_user() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_send_user(ArgT0&& arg0, ArgT... args);
  std::string* mutable_send_user();
  PROTOBUF_NODISCARD std::string* release_send_user();
  void set_allocated_send_user(std::string* send_user);
  private:
  const std::string& _internal_send_user() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_send_user(const std::string& value);
  std::string* _internal_mutable_send_user();
  public:

  // string recv_user = 3;
  void clear_recv_user();
  const std::string& recv_user() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_recv_user(ArgT0&& arg0, ArgT... args);
  std::string* mutable_recv_user();
  PROTOBUF_NODISCARD std::string* release_recv_user();
  void set_allocated_recv_user(std::string* recv_user);
  private:
  const std::string& _internal_recv_user() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_recv_user(const std::string& value);
  std::string* _internal_mutable_recv_user();
  public:

  // string message_all = 4;
  void clear_message_all();
  const std::string& message_all() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message_all(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message_all();
  PROTOBUF_NODISCARD std::string* release_message_all();
  void set_allocated_message_all(std::string* message_all);
  private:
  const std::string& _internal_message_all() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message_all(const std::string& value);
  std::string* _internal_mutable_message_all();
  public:

  // @@protoc_insertion_point(class_scope:Protocol.BuffData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr send_time_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr send_user_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr recv_user_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_all_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Login

// bool allow = 1;
inline void Login::clear_allow() {
  allow_ = false;
}
inline bool Login::_internal_allow() const {
  return allow_;
}
inline bool Login::allow() const {
  // @@protoc_insertion_point(field_get:Protocol.Login.allow)
  return _internal_allow();
}
inline void Login::_internal_set_allow(bool value) {
  
  allow_ = value;
}
inline void Login::set_allow(bool value) {
  _internal_set_allow(value);
  // @@protoc_insertion_point(field_set:Protocol.Login.allow)
}

// string user_name = 2;
inline void Login::clear_user_name() {
  user_name_.ClearToEmpty();
}
inline const std::string& Login::user_name() const {
  // @@protoc_insertion_point(field_get:Protocol.Login.user_name)
  return _internal_user_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Login::set_user_name(ArgT0&& arg0, ArgT... args) {
 
 user_name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.Login.user_name)
}
inline std::string* Login::mutable_user_name() {
  std::string* _s = _internal_mutable_user_name();
  // @@protoc_insertion_point(field_mutable:Protocol.Login.user_name)
  return _s;
}
inline const std::string& Login::_internal_user_name() const {
  return user_name_.Get();
}
inline void Login::_internal_set_user_name(const std::string& value) {
  
  user_name_.Set(value, GetArenaForAllocation());
}
inline std::string* Login::_internal_mutable_user_name() {
  
  return user_name_.Mutable(GetArenaForAllocation());
}
inline std::string* Login::release_user_name() {
  // @@protoc_insertion_point(field_release:Protocol.Login.user_name)
  return user_name_.Release();
}
inline void Login::set_allocated_user_name(std::string* user_name) {
  if (user_name != nullptr) {
    
  } else {
    
  }
  user_name_.SetAllocated(user_name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (user_name_.IsDefault()) {
    user_name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.Login.user_name)
}

// -------------------------------------------------------------------

// BuffData

// string send_time = 1;
inline void BuffData::clear_send_time() {
  send_time_.ClearToEmpty();
}
inline const std::string& BuffData::send_time() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.send_time)
  return _internal_send_time();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void BuffData::set_send_time(ArgT0&& arg0, ArgT... args) {
 
 send_time_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.BuffData.send_time)
}
inline std::string* BuffData::mutable_send_time() {
  std::string* _s = _internal_mutable_send_time();
  // @@protoc_insertion_point(field_mutable:Protocol.BuffData.send_time)
  return _s;
}
inline const std::string& BuffData::_internal_send_time() const {
  return send_time_.Get();
}
inline void BuffData::_internal_set_send_time(const std::string& value) {
  
  send_time_.Set(value, GetArenaForAllocation());
}
inline std::string* BuffData::_internal_mutable_send_time() {
  
  return send_time_.Mutable(GetArenaForAllocation());
}
inline std::string* BuffData::release_send_time() {
  // @@protoc_insertion_point(field_release:Protocol.BuffData.send_time)
  return send_time_.Release();
}
inline void BuffData::set_allocated_send_time(std::string* send_time) {
  if (send_time != nullptr) {
    
  } else {
    
  }
  send_time_.SetAllocated(send_time, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (send_time_.IsDefault()) {
    send_time_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.BuffData.send_time)
}

// string send_user = 2;
inline void BuffData::clear_send_user() {
  send_user_.ClearToEmpty();
}
inline const std::string& BuffData::send_user() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.send_user)
  return _internal_send_user();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void BuffData::set_send_user(ArgT0&& arg0, ArgT... args) {
 
 send_user_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.BuffData.send_user)
}
inline std::string* BuffData::mutable_send_user() {
  std::string* _s = _internal_mutable_send_user();
  // @@protoc_insertion_point(field_mutable:Protocol.BuffData.send_user)
  return _s;
}
inline const std::string& BuffData::_internal_send_user() const {
  return send_user_.Get();
}
inline void BuffData::_internal_set_send_user(const std::string& value) {
  
  send_user_.Set(value, GetArenaForAllocation());
}
inline std::string* BuffData::_internal_mutable_send_user() {
  
  return send_user_.Mutable(GetArenaForAllocation());
}
inline std::string* BuffData::release_send_user() {
  // @@protoc_insertion_point(field_release:Protocol.BuffData.send_user)
  return send_user_.Release();
}
inline void BuffData::set_allocated_send_user(std::string* send_user) {
  if (send_user != nullptr) {
    
  } else {
    
  }
  send_user_.SetAllocated(send_user, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (send_user_.IsDefault()) {
    send_user_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.BuffData.send_user)
}

// string recv_user = 3;
inline void BuffData::clear_recv_user() {
  recv_user_.ClearToEmpty();
}
inline const std::string& BuffData::recv_user() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.recv_user)
  return _internal_recv_user();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void BuffData::set_recv_user(ArgT0&& arg0, ArgT... args) {
 
 recv_user_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.BuffData.recv_user)
}
inline std::string* BuffData::mutable_recv_user() {
  std::string* _s = _internal_mutable_recv_user();
  // @@protoc_insertion_point(field_mutable:Protocol.BuffData.recv_user)
  return _s;
}
inline const std::string& BuffData::_internal_recv_user() const {
  return recv_user_.Get();
}
inline void BuffData::_internal_set_recv_user(const std::string& value) {
  
  recv_user_.Set(value, GetArenaForAllocation());
}
inline std::string* BuffData::_internal_mutable_recv_user() {
  
  return recv_user_.Mutable(GetArenaForAllocation());
}
inline std::string* BuffData::release_recv_user() {
  // @@protoc_insertion_point(field_release:Protocol.BuffData.recv_user)
  return recv_user_.Release();
}
inline void BuffData::set_allocated_recv_user(std::string* recv_user) {
  if (recv_user != nullptr) {
    
  } else {
    
  }
  recv_user_.SetAllocated(recv_user, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (recv_user_.IsDefault()) {
    recv_user_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.BuffData.recv_user)
}

// string message_all = 4;
inline void BuffData::clear_message_all() {
  message_all_.ClearToEmpty();
}
inline const std::string& BuffData::message_all() const {
  // @@protoc_insertion_point(field_get:Protocol.BuffData.message_all)
  return _internal_message_all();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void BuffData::set_message_all(ArgT0&& arg0, ArgT... args) {
 
 message_all_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.BuffData.message_all)
}
inline std::string* BuffData::mutable_message_all() {
  std::string* _s = _internal_mutable_message_all();
  // @@protoc_insertion_point(field_mutable:Protocol.BuffData.message_all)
  return _s;
}
inline const std::string& BuffData::_internal_message_all() const {
  return message_all_.Get();
}
inline void BuffData::_internal_set_message_all(const std::string& value) {
  
  message_all_.Set(value, GetArenaForAllocation());
}
inline std::string* BuffData::_internal_mutable_message_all() {
  
  return message_all_.Mutable(GetArenaForAllocation());
}
inline std::string* BuffData::release_message_all() {
  // @@protoc_insertion_point(field_release:Protocol.BuffData.message_all)
  return message_all_.Release();
}
inline void BuffData::set_allocated_message_all(std::string* message_all) {
  if (message_all != nullptr) {
    
  } else {
    
  }
  message_all_.SetAllocated(message_all, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (message_all_.IsDefault()) {
    message_all_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:Protocol.BuffData.message_all)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto