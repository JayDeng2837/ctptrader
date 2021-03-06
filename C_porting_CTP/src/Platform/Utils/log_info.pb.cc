// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: lcts/log_info.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "log_info.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* LogInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LogInfo_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_lcts_2flog_5finfo_2eproto() {
  protobuf_AddDesc_lcts_2flog_5finfo_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "lcts/log_info.proto");
  GOOGLE_CHECK(file != NULL);
  LogInfo_descriptor_ = file->message_type(0);
  static const int LogInfo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogInfo, pri_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogInfo, log_str_),
  };
  LogInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      LogInfo_descriptor_,
      LogInfo::default_instance_,
      LogInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LogInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(LogInfo));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_lcts_2flog_5finfo_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    LogInfo_descriptor_, &LogInfo::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_lcts_2flog_5finfo_2eproto() {
  delete LogInfo::default_instance_;
  delete LogInfo_reflection_;
}

void protobuf_AddDesc_lcts_2flog_5finfo_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023lcts/log_info.proto\"\'\n\007LogInfo\022\013\n\003pri\030"
    "\001 \002(\005\022\017\n\007log_str\030\002 \002(\tB\002H\001", 66);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "lcts/log_info.proto", &protobuf_RegisterTypes);
  LogInfo::default_instance_ = new LogInfo();
  LogInfo::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_lcts_2flog_5finfo_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_lcts_2flog_5finfo_2eproto {
  StaticDescriptorInitializer_lcts_2flog_5finfo_2eproto() {
    protobuf_AddDesc_lcts_2flog_5finfo_2eproto();
  }
} static_descriptor_initializer_lcts_2flog_5finfo_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int LogInfo::kPriFieldNumber;
const int LogInfo::kLogStrFieldNumber;
#endif  // !_MSC_VER

LogInfo::LogInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void LogInfo::InitAsDefaultInstance() {
}

LogInfo::LogInfo(const LogInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void LogInfo::SharedCtor() {
  _cached_size_ = 0;
  pri_ = 0;
  log_str_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

LogInfo::~LogInfo() {
  SharedDtor();
}

void LogInfo::SharedDtor() {
  if (log_str_ != &::google::protobuf::internal::kEmptyString) {
    delete log_str_;
  }
  if (this != default_instance_) {
  }
}

void LogInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LogInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LogInfo_descriptor_;
}

const LogInfo& LogInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_lcts_2flog_5finfo_2eproto();
  return *default_instance_;
}

LogInfo* LogInfo::default_instance_ = NULL;

LogInfo* LogInfo::New() const {
  return new LogInfo;
}

void LogInfo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    pri_ = 0;
    if (has_log_str()) {
      if (log_str_ != &::google::protobuf::internal::kEmptyString) {
        log_str_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool LogInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 pri = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &pri_)));
          set_has_pri();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_log_str;
        break;
      }

      // required string log_str = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_log_str:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_log_str()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->log_str().data(), this->log_str().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void LogInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 pri = 1;
  if (has_pri()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->pri(), output);
  }

  // required string log_str = 2;
  if (has_log_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->log_str().data(), this->log_str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->log_str(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* LogInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 pri = 1;
  if (has_pri()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->pri(), target);
  }

  // required string log_str = 2;
  if (has_log_str()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->log_str().data(), this->log_str().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->log_str(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int LogInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 pri = 1;
    if (has_pri()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->pri());
    }

    // required string log_str = 2;
    if (has_log_str()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->log_str());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LogInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const LogInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const LogInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void LogInfo::MergeFrom(const LogInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_pri()) {
      set_pri(from.pri());
    }
    if (from.has_log_str()) {
      set_log_str(from.log_str());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void LogInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogInfo::CopyFrom(const LogInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogInfo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void LogInfo::Swap(LogInfo* other) {
  if (other != this) {
    std::swap(pri_, other->pri_);
    std::swap(log_str_, other->log_str_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata LogInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LogInfo_descriptor_;
  metadata.reflection = LogInfo_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
