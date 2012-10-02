// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PacketCore.proto

#ifndef PROTOBUF_PacketCore_2eproto__INCLUDED
#define PROTOBUF_PacketCore_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace PacketCore {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_PacketCore_2eproto();
void protobuf_AssignDesc_PacketCore_2eproto();
void protobuf_ShutdownFile_PacketCore_2eproto();

class Auth;

// ===================================================================

class Auth : public ::google::protobuf::Message {
 public:
  Auth();
  virtual ~Auth();
  
  Auth(const Auth& from);
  
  inline Auth& operator=(const Auth& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Auth& default_instance();
  
  void Swap(Auth* other);
  
  // implements Message ----------------------------------------------
  
  Auth* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Auth& from);
  void MergeFrom(const Auth& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required int32 EncryptionKey = 1;
  inline bool has_encryptionkey() const;
  inline void clear_encryptionkey();
  static const int kEncryptionKeyFieldNumber = 1;
  inline ::google::protobuf::int32 encryptionkey() const;
  inline void set_encryptionkey(::google::protobuf::int32 value);
  
  // @@protoc_insertion_point(class_scope:PacketCore.Auth)
 private:
  inline void set_has_encryptionkey();
  inline void clear_has_encryptionkey();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::google::protobuf::int32 encryptionkey_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  friend void  protobuf_AddDesc_PacketCore_2eproto();
  friend void protobuf_AssignDesc_PacketCore_2eproto();
  friend void protobuf_ShutdownFile_PacketCore_2eproto();
  
  void InitAsDefaultInstance();
  static Auth* default_instance_;
};
// ===================================================================


// ===================================================================

// Auth

// required int32 EncryptionKey = 1;
inline bool Auth::has_encryptionkey() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Auth::set_has_encryptionkey() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Auth::clear_has_encryptionkey() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Auth::clear_encryptionkey() {
  encryptionkey_ = 0;
  clear_has_encryptionkey();
}
inline ::google::protobuf::int32 Auth::encryptionkey() const {
  return encryptionkey_;
}
inline void Auth::set_encryptionkey(::google::protobuf::int32 value) {
  set_has_encryptionkey();
  encryptionkey_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace PacketCore

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_PacketCore_2eproto__INCLUDED
